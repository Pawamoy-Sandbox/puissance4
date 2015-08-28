CC = gcc

ifeq ($(DEBUG),yes)
	CFLAGS = -Wall -g
else
	CFLAGS = -Wall
endif

OBJ = ./obj/

vpath %.c = ./src/
vpath %.o = ./obj/
vpath %.h = ./include/

main : main.o PileB.o PileH.o P4.o jeu.o io.o
	$(CC) $(CFLAGS) -o $@ $(OBJ)main.o $(OBJ)PileB.o $(OBJ)PileH.o $(OBJ)P4.o $(OBJ)jeu.o $(OBJ)io.o
	mv $@ bin/

main.o : main.c P4.h jeu.h io.h
PileB.o : PileB.c PileB.h base.h
PileH.o : PileH.c PileH.h base.h
P4.o : P4.c P4.h base.h
jeu.o : jeu.c jeu.h P4.h
io.o : io.c io.h P4.h jeu.h

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<
	mv $@ obj/

clean : 
	rm $(OBJ)*.o ./bin/main

archive : 
	tar -f puissance4.tar.gz -cvz src/*.c include/*.h Makefile Doxyfile Rapport.pdf

run :
	bin/main
	
debug :
	gdb ./bin/main
	
valgrind :
	valgrind ./bin/main
	
doc :
	doxygen Doxyfile

cleandoc :
	rm -rf doc
