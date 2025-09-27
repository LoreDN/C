# Variables
CC = gcc
CFLAGS = -Wall -static

# Project Sources
SRC_INT = myList_int.c
SRC_FLOAT = myList_float.c
SRC_PROJECT = main.c # ---------- Project '.c' file

# Assembly Sources
ASM_DIR = assembly
ASM_SRC = swap copy length
ASM_OBJ_INT = $(patsubst %, $(ASM_DIR)/list_%_int.o, $(ASM_SRC))
ASM_OBJ_FLOAT = $(patsubst %, $(ASM_DIR)/list_%_float.o, $(ASM_SRC))

# Binaries
EXEC_INT = main_int
EXEC_FLOAT = main_float
EXEC_INT_FLOAT = main_int_float


# ================== Compiling Assembly Optimized Functions ==================

# ASM_OBJ_INT Rule
$(ASM_DIR)/list_%_int.o: $(ASM_DIR)/list_%.S
	@$(CC) -c $< -DINT_TYPE -o $@

# ASM_OBJ_INT Rule
$(ASM_DIR)/list_%_float.o: $(ASM_DIR)/list_%.S
	@$(CC) -c $< -DFLOAT_TYPE -o $@


# ========================= Compiling Project C Code =========================

# EXEC_INT Rule
$(EXEC_INT): $(SRC_INT) $(SRC_PROJECT) $(ASM_OBJ_INT)
	$(CC) $(CFLAGS) $^ -o $@ -lm
	@rm -f $(ASM_OBJ_INT)

# EXEC_FLOAT Rule
$(EXEC_FLOAT): $(SRC_FLOAT) $(SRC_PROJECT) $(ASM_OBJ_FLOAT)
	$(CC) $(CFLAGS) $^ -o $@ -lm
	@rm -f $(ASM_OBJ_FLOAT)

# EXEC_INT_FLOAT Rule
$(EXEC_INT_FLOAT): $(SRC_INT) $(SRC_FLOAT) $(SRC_PROJECT) $(ASM_OBJ_INT) $(ASM_OBJ_FLOAT)
	$(CC) $(CFLAGS) $^ -o $@ -lm
	@rm -f $(ASM_OBJ_INT) $(ASM_OBJ_FLOAT)


# =============================== Running Rules ==============================

# Run EXEC_INT Rule
run_int: $(EXEC_INT)
	./$(EXEC_INT)

# Run EXEC_FLOAT Rule
run_float: $(EXEC_FLOAT)
	./$(EXEC_FLOAT)

# Run EXEC_INT&FLOAT Rule
run_int_float: $(EXEC_INT_FLOAT)
	./$(EXEC_INT_FLOAT)


# ============================== Cleaning Rules ==============================

# Clean EXEC_INT Rule
clean_int:
	rm -f $(EXEC_INT)

# Clean EXEC_FLOAT Rule
clean_float:
	rm -f $(EXEC_FLOAT)

# Clean EXEC_INT_FLOAT Rule
clean_int_float:
	rm -f $(EXEC_INT_FLOAT)