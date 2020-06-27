# StudentName: Dan Wu
# University of Melbourne 
# Algorithms and Data Structure project1

CC = gcc
CFLAGS = -Wall -std=c99
OBJ = Node1.o Node2.o

SUBMISSION = Makefile dict1.c dict2.c Node1.h Node1.c \
			 Node2.h Node2.c

help:
	@echo "Usage:"
	@echo "    make stage1"
	@echo "    make stage2"
	@echo "    make clean"
	@echo "    make submission"


stage1: $(OBJ) dict1.o
	$(CC) $(CFLAGS) -o stage1 $(OBJ) dict1.o

stage2: $(OBJ) dict2.o
	$(CC) $(CFLAGS) -o stage2 $(OBJ) dict2.o

dict1.o: Node1.h
dict2.o: Node2.h
Node1.o: Node1.h
Node2.o: Node2.h

clean:
	rm -f $(OBJ) dict1.o dict2.o stage1 stage2

submission:
	zip assmnt1.zip $(SUBMISSION)
