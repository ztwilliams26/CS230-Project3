CODE = lab.c parser.c main.c bst.c
OBJ = lab.o parser.o main.o bst.o
PROG = wordfreak

$(PROG) : $(OBJ)
	gcc $(OBJ) -o $(PROG)

$(OBJ) : $(CODE)
	gcc -c $(CODE) -o $(OBJ)
