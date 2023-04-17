CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g

SRCS = els.c file_checking.c
OBJS = $(SRCS:.c=.o)
HEADERS = els.h file_checking.h

.PHONY: all clean

all: els

els: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) els
