CC = gcc
CFLAGS = -Wall -Werror
SRC = els.c file_checking.c
OBJ = $(SRC:.c=.o)
DEPS = file_checking.h

all: els

els: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -f $(OBJ) els
