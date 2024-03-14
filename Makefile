# Source files
SRC = app.c domain/med.c repository/repo.c service/service.c ui/ui.c
# Object files
OBJ = $(SRC:.c=.o)

# Compiler flags
CFLAGS = -Wall -g -fprofile-arcs -ftest-coverage

# Rule to build the application
app: $(OBJ)
	gcc -c -o $@ $< $(CFLAGS)
