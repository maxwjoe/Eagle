
# === COMPILATION OPTIONS ===

CXX=g++
CXXFLAGS=

# === PATHS ===

BIN_DIR=bin
INCLUDE_DIR=../include
LIB_DIR=../lib

# === FILES ===

EXAMPLE_NAME=testBed

# === RULES ===

$(BIN_DIR)/$(EXAMPLE_NAME) : $(EXAMPLE_NAME).cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -o $@ $^ -L. -l:$(LIB_DIR)/testClass.a

clean :
	rm -r $(BIN_DIR)/*