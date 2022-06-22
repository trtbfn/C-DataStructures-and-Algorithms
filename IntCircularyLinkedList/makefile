CC = gcc
CFLAGS = -Wall
EXECUTABLE = list
list: circularylinkedlist.o main.o
	$(CC) $(CFLAGS) circularylinkedlist.o main.o -o $(EXECUTABLE)
circularylinkedlist.o: circularylinkedlist.h
main.o: main.c
clean: 
	rm -rf *.o 
leaks: 
	valgrind --leak-check=yes ./$(EXECUTABLE)