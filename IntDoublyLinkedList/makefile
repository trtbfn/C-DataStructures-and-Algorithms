CC = gcc
CFLAGS = -Wall
EXECUTABLE = list
list: doublylinkedlist.o main.o
	$(CC) $(CFLAGS) doublylinkedlist.o main.o -o $(EXECUTABLE)
doublylinkedlist.o: doublylinkedlist.h
main.o: main.c
clean: 
	rm -rf *.o 
leaks: 
	valgrind --leak-check=yes ./$(EXECUTABLE)