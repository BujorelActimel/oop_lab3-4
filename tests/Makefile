# Source files
SRC = ../domain/med.c ../repository/repo.c ../service/service.c
# Object files
OBJ = $(SRC:.c=.o)

# Test source files
TEST_SRC = $(wildcard *.c)
# Test object files
TEST_OBJ = $(TEST_SRC:.c=.o) $(OBJ)

# Compiler flags
CFLAGS = -Wall -g

# Rule to compile and run tests
tests_exec: $(TEST_OBJ)
	gcc -o $@ $^ $(CFLAGS)
	./tests_exec