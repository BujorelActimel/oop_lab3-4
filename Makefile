CC=gcc
CFLAGS=-Wall -g
OBJ=app.o domain/med.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

domain/%.o: domain/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

app: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) app