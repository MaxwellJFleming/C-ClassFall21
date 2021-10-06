CC = gcc
CFLAGS = -I. -Wall -Wextra -Werror -O2 -pedantic -std=c99
DEPS = logic.h
OBJ = logic.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

app: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm *.o app
