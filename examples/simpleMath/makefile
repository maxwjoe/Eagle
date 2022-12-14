
# === COMPILATION OPTIONS ===

CXX=g++
CXXFLAGS=


# === PATHS ===

EXAMPLE_SRC_DIR=src
EXAMPLE_INCLUDE_DIR=include

EAGLE_INCLUDE_DIR=../../include
EAGLE_LIB_DIR=../../lib

OBJ_DIR=obj
BIN_DIR=bin

# === FILES ===

EXAMPLE_EXE_NAME=testMyMaths
EAGLE_LIB_NAME=libEagle

# === RULES ===

all : $(BIN_DIR)/$(EXAMPLE_EXE_NAME)

# Build mymathfuncs Object
$(OBJ_DIR)/mymathsfuncs.o : $(EXAMPLE_SRC_DIR)/mymathfuncs.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(EXAMPLE_INCLUDE_DIR) -c $< -o $@


# Build Example
$(BIN_DIR)/$(EXAMPLE_EXE_NAME) : testBed.cpp $(OBJ_DIR)/mymathsfuncs.o
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -I$(EXAMPLE_INCLUDE_DIR) -I$(EAGLE_INCLUDE_DIR) -o $@ $^ -L. -l:$(EAGLE_LIB_DIR)/$(EAGLE_LIB_NAME).a

clean :
	rm -r $(OBJ_DIR) $(BIN_DIR)