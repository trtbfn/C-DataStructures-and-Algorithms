CC = gcc
CFLAGS = -Wall
EXECUTABLE = list
list: circularlinkedlist.o main.o
	$(CC) $(CFLAGS) circularlinkedlist.o main.o -o $(EXECUTABLE)
linkedlist.o: circularlinkedlist.h
main.o: main.c
clean: 
	rm -rf *.o 
leaks: 
	valgrind --leak-check=yes ./$(EXECUTABLE)