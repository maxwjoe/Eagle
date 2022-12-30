# === COMPILER OPTIONS ===

CC=gcc

CFLAGS=
CFLAGS_DEBUG=-Wall -Werror -g -fsanitize=address,leak,undefined

# === PATHS ===

SRC_DIR=src
OBJ_DIR=obj
LIB_DIR=lib
INCLUDE_DIR=include
BIN_DIR=bin

# === FILES ===

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

EXAMPLE_EXEC = example
EXAMPLE_SRC = $(SRC_DIR)/EagleTest.c
STATIC_LIB_NAME = libEagleStatic
DYNAMIC_LIB_NAME = libEagle

# === RULES ===

all : $(LIB_DIR)/$(STATIC_LIB_NAME).a $(LIB_DIR)/$(DYNAMIC_LIB_NAME).so $(LIB_DIR)/libEagleMac.1.dylib

# Build Objects
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Build Static Library (Linux)
$(LIB_DIR)/$(STATIC_LIB_NAME).a : $(OBJ_FILES)
	mkdir -p $(LIB_DIR)
	ar rcs $(LIB_DIR)/$(STATIC_LIB_NAME).a $(OBJ_FILES)
	rm -r $(OBJ_DIR)

# Build Dynamic Library (Linux)
$(LIB_DIR)/$(DYNAMIC_LIB_NAME).so : $(SRC_FILES)
	mkdir -p $(LIB_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -fPIC -shared -o $@ $(SRC_FILES) -lc

# Build Dynamic Library (macOS)
$(LIB_DIR)/libEagleMac.1.dylib : $(SRC_FILES)
	mkdir -p $(LIB_DIR)
	mkdir -p ./example/lib
	$(CC) -I$(INCLUDE_DIR) -dynamiclib -o $(LIB_DIR)/$(DYNAMIC_LIB_NAME).dylib $(SRC_FILES)
	cp $(LIB_DIR)/$(DYNAMIC_LIB_NAME).dylib ./example/lib/libEagle.dylib
clean:
	rm -r $(LIB_DIR) $(OBJ_DIR) $(BIN_DIR)
	