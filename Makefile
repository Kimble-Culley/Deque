CC = g++
CFLAGS = -g -Wall -Wextra

default: TEST

TEST: deque.o main.o
	$(CC) $(CFLAGS) -o TEST deque.o main.o

deque.o: deque.cpp deque.h
	$(CC) $(CFLAGS) -c deque.cpp

main.o: main.cpp deque.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) deque *.o *~
