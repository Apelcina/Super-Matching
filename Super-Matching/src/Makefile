

CC=g++
CFLAGS=-I.
DEPS = test_funcs.h utility_funcs.h
OBJ = Application.o test_funcs.o utility_funcs.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
SuperMatching: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o
