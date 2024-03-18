# Source files
SRC = app.c domain/med.c repository/repo.c service/service.c ui/ui.c
# Object files
OBJ = $(SRC:.c=.o)

# Compiler flags
CFLAGS = -Wall -g

# Rule to build the object files
%.o: %.c
	gcc -c -o $@ $< $(CFLAGS)

# Rule to build the application
app: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

# Rule to clean the build
.PHONY: clean
clean:
	rm -f $(OBJ) app