
# === COMPILATION OPTIONS ===

CXX=g++
CXXFLAGS=

# === PATHS ===

SRC_DIR=src
INCLUDE_DIR=include
OBJ_DIR=obj
BIN_DIR=bin
LIB_DIR=lib

# === FILES ===

SRC_FILES=$(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES=$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

LIB_NAME=libEagle

# === RULES ===

all : $(LIB_DIR)/$(LIB_NAME).a

# Object Files
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Static Library
$(LIB_DIR)/$(LIB_NAME).a : $(OBJ_FILES)
	mkdir -p $(LIB_DIR)
	ar rcs $(LIB_DIR)/$(LIB_NAME).a $(OBJ_FILES)
	rm -r $(OBJ_DIR)


clean :
	rm -r $(LIB_DIR)
