all: main.c generator.c Dijkstra.c solver.c reader.c BFS.c
	gcc -o ./gensolvegraph main.c generator.c Dijkstra.c solver.c reader.c BFS.c

#DDOMYSLNE WYWOLANIA 

default: 
	./gensolvegraph -out 1.dat -in 1.dat
test1: 
	./gensolvegraph -out 1.dat -from 1 -to 100 	
test2: 
	./gensolvegraph -in 1.dat -start 2 -finish 28
test3:
	./gensolvegraph -out 2.dat -row 10 -column 20 -from 0.0001 -to 50 
test4:
	./gensolvegraph -out 1.dat -in 1.dat -row 10 -column 15 -from 1 -to 10 -start 10 - finish 20
test5:
	./gensolvegraph -out 1.dat -in 1.dat -start 2 -finish 15

#TEST OBSLUGI BLEDOW:

error1:
	valgrind ./gensolvegraph #kod błędu 1
error2:
	valgrind ./gensolvegraph -in 1.txt #kod błędu 2
error3: 
	valgrind ./gensolvegraph -in bad.txt #kod błędu 3
error4: 
	valgrind ./gensolvegraph -out 3.txt -in 3.txt -mode 1 #kod błędu 4
error5: 
	valgrind ./gensolvegraph -out 1.dat -in 1.dat -row 10 -column -2 -from 2.1 -to 2.5 #kod błędu 5 
error6: 
	valgrind ./gensolvegraph -out 3.txt -in 3.txt -row 3 -column 3 -start 1 -finish 10 #kod błędu 6

#ZWALNIANIE PAMIECI

memorycheck:
	valgrind --leak-check=full ./gensolvegraph -out 1.dat -in 1.dat 

#DEBUGGING

DJIKSTRA:
	gcc -o ./gensolvegraph main.c generator.c Dijkstra.c solver.c reader.c BFS.c -D_DEBUG
READER_AND_GENERATOR:
	gcc -o ./gensolvegraph *.c -D_READER
BFS:
	gcc -o ./gensolvegraph *.c -D_BFS 
