CC=gcc
CFLAGS=-Wall -g
OBJ=app.o domain/med.o ui/ui.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

domain/%.o: domain/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

ui/%.o: ui/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

app: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

med_tests: tests/test_domain.c
	gcc -I domain tests/test_domain.c domain/med.c -o med_tests
	./med_tests

.PHONY: clean

clean:
	rm -f domain/*.o ui/*.o *~ core $(INCDIR)/*~ 
	rm -f app
	rm -f med_tests