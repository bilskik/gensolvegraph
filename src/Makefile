all: main.c generator.c Dijkstra.c solver.c reader.c BFS.c
	gcc -o ./gensolvegraph main.c generator.c Dijkstra.c solver.c reader.c BFS.c

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

#TEST OBSLUGI BLEDOW:

error1:
	./gensolvegraph #kod błędu 1
error2:
	./gensolvegraph -in 1.txt 
error3: 
	./gensolvegraph -in bad.txt
error5: 
	./gensolvegraph -out 3.txt -in 3.txt -row 3 -column 3 -start 1 -finish 10
error6: 
	./gensolvegraph -out 3.txt -in 3.txt -mode 1
#CHECKING IF MEMORY WAS FREED

memorycheck:
	valgrind --leak-check=full --track-origins=yes  ./gensolvegraph -out 1.dat -in 1.dat 

