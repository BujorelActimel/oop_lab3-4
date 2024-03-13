# Source files
SRC = app.c domain/med.c repository/repo.c ui/ui.c
# Object files
OBJ = $(SRC:.c=.o)

# Compiler flags
CFLAGS = -Wall -g

# Rule to build the application
app: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)