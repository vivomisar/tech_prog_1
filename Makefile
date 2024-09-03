CC=clang++
SRC=queue.cpp queue1.cpp queue2.cpp queue3.cpp main.cpp
NAME=lab1
CFLAGS=-Wall -std=c++17 -g

all:
	$(CC) -o $(NAME) $(SRC) $(CFLAGS)

run: all
	./$(NAME)