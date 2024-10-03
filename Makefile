#Makefile
CC = gcc
CFLAGS = -Wall -g
SRCS = asst6.c heap.c

OBJS = $(SRCS:.c=.o)

EXEC = asst6

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean
