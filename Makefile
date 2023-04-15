CC = gcc
CFLAGS = -Wall -Wextra -pedantic

all: els

els: els.c
	$(CC) $(CFLAGS) -o els els.c

clean:
	rm -f els
