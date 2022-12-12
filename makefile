# === Build Test Library ===

# --- Compiler Options ---

CC=g++

# --- File Options ---

SRC_DIR=src
OBJ_DIR=obj
LIB_DIR=lib
BUILD_DIR=build
INCLUDE_DIR=include

STATIC_LIB_NAME=libEagle
TEST_EXEC_NAME=test

SRC_FILES=$(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES=$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# === BUILD RULES ===

all : $(LIB_DIR)/$(LIB_EAGLE).a $(BUILD_DIR)/$(TEST_EXEC_NAME)

# Build Objects
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@


# Build Static Library
$(LIB_DIR)/$(LIB_EAGLE).a : $(OBJ_FILES)
	ar rcs $(LIB_DIR)/$(STATIC_LIB_NAME).a $(OBJ_FILES)

# Statically Link Test File
$(BUILD_DIR)/$(TEST_EXEC_NAME) : main.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $@ $^ -L. -l:$(LIB_DIR)/$(STATIC_LIB_NAME).a

clean:
	rm -r $(OBJ_DIR)/* $(BUILD_DIR)/* $(LIB_DIR)/*