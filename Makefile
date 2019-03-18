main.o: main.c
	gcc main.c -c main.o
BST.o: BST.o
	gcc BST.c -c BST.o
parser.o: parser.o
	gcc parser.c -c parser.o

wordfreak:main.o parser.o BST.o
	gcc main.o -o parser.o -o BST.o -o wordfreak
