CC = gcc
CFLAGS = -Wall
EXECUTABLE = list
list: linked-list.o main.o
	$(CC) $(CFLAGS) linked-list.o main.o -o $(EXECUTABLE)
linked-list.o: linked-list.h
main.o: main.c
clean: 
	rm -rf *.o 
leaks: 
	valgrind --leak-check=yes ./$(EXECUTABLE)