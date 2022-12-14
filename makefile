
# === COMPILATION OPTIONS ===

CXX=g++
CXXFLAGS=

# === PATHS ===

SRC_DIR=src
INCLUDE_DIR=include
OBJ_DIR=obj
BIN_DIR=bin
LIB_DIR=lib

TEST_EXE_NAME=testBed

# === FILES ===

SRC_FILES=$(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES=$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# === RULES ===

all : $(LIB_DIR)/testClass.a $(BIN_DIR)/$(TEST_EXE_NAME)

# Object Files
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Static Library
$(LIB_DIR)/testClass.a : $(OBJ_FILES)
	ar rcs $(LIB_DIR)/testClass.a $(OBJ_FILES)

# Build Example (Linked against static library)
$(BIN_DIR)/$(TEST_EXE_NAME) : testBed.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -o $@ $^ -L. -l:$(LIB_DIR)/testClass.a

clean :
	rm -r $(OBJ_DIR)/* $(BIN_DIR)/* $(LIB_DIR)/%