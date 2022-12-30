
# === COMPILER OPTIONS ===


CC=gcc
CFLAGS=

# === PATHS ===

EAGLE_PATH=../lib
EAGLE_INCLUDE=../include
EAGLE_LIB_NAME=libEagle
BIN_DIR=bin
OBJ_DIR=obj
EXEC_NAME=example

# === RULES ===

all :  example.o

# Build example and link against dynamic library (Linux)
$(OBJ_DIR)/example.o : testBed.c calc.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(EAGLE_INCLUDE) -o $@ $^ -L. -l:$(EAGLE_PATH)/$(EAGLE_LIB_NAME).so

# Build example and link against dynamic library (MacOS)
example.o : testBed.c calc.c
	mkdir -p $(OBJ_DIR) lib
	$(CC) $(CFLAGS) -v -I$(EAGLE_INCLUDE) -o $@ $^ -L../lib -lEagle

clean :
	rm -r lib
	rm example.o