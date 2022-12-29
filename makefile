# === COMPILER OPTIONS ===

CC=gcc
CFLAGS=-Wall -Werror -g -fsanitize=address,leak,undefined

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
STATIC_LIB_NAME = libEagle

# === RULES ===

all : $(LIB_DIR)/$(STATIC_LIB_NAME).a $(BIN_DIR)/$(EXAMPLE_EXEC)

# Build Objects
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Build Static Library
$(LIB_DIR)/$(STATIC_LIB_NAME).a : $(OBJ_FILES)
	mkdir -p $(LIB_DIR)
	ar rcs $(LIB_DIR)/$(STATIC_LIB_NAME).a $(OBJ_FILES)

# Example Executable
$(BIN_DIR)/$(EXAMPLE_EXEC) : $(EXAMPLE_SRC)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $@ $^ -L. -l:$(LIB_DIR)/$(STATIC_LIB_NAME).a

clean:
	rm -r $(LIB_DIR) $(OBJ_DIR) $(BIN_DIR)