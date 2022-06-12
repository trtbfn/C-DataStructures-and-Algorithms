CC = gcc
CFLAGS = -Wall
EXECUTABLE = list
list: linkedlist.o main.o
	$(CC) $(CFLAGS) linkedlist.o main.o -o $(EXECUTABLE)
linkedlist.o: linkedlist.h
main.o: main.c
clean: 
	rm -rf *.o 
leaks: 
	valgrind --leak-check=yes ./$(EXECUTABLE)