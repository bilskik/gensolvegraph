all: main.c generator.c searcher.c solver.c reader.c BFS.c
	gcc -o ./gensolvegraph main.c generator.c searcher.c solver.c reader.c BFS.c

default: 
	./gensolvegraph -out 1.dat -in 1.dat
test1: 
	./gensolvegraph -out 1.dat -from 1 -to 100
test2: 
	./gensolvegraph -out 1.dat -in 1.dat -start 2 -finish 28
test3:
	./gensolvegraph
test4:
	./gensolvegraph -out 2.dat -row 10 -column 200 -from 0.0001 -to 50 
test5:
	./gensolvegraph -out 1.dat -in 1.dat -row 20 -column 20 -from 1 -to 10 -start 10 - finish 20
test6:
	./gensolvegraph -in 1.dat
memory_check:
	valgrind --leak-check=full --track-origins=yes ./gensolvegraph -out 1.dat -in 1.dat 

