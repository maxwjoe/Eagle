
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

$(OBJ_DIR)/example.o : testBed.c calc.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(EAGLE_INCLUDE) -o $@ $^ -L. -l:$(EAGLE_PATH)/$(EAGLE_LIB_NAME).a

clean :
	rm -r $(OBJ_DIR)