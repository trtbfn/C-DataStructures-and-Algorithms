CC = gcc
CFLAGS = -Wall -Wextra
CFLAGS += -g 
CFLAGS += -fsanitize=address

all: linkedlist

linkedlist.o: linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -c $< -o $@

script.o: script.c 
	$(CC) $(CFLAGS) -c $< -o $@

linkedlist: linkedlist.o script.o
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	rm -f %.o