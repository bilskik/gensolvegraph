//Sorry for my english, a description and an usage to check, chyba że piszemy po polsku?
#include "generator.h"

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
static struct option long_options[] =
{
    {"input", required_argument, 0, 'i'},
    {"output", required_argument, 0, 'o'},
    {"row", required_argument, 0, 'r'},
    {"column", required_argument, 0, 'c'},
    {"from", required_argument, 0, 'f'},
    {"to", required_argument, 0, 't'},
	{"start", required_argument, 0, 's'},
	{"finish", required_argument, 0, 'e'},
    {0, 0, 0, 0}
};

void write_usage(){
printf("Usage:\n\t-[o] out <output file> -in [i] <input file> -[r] row <number of rows in a graph> -[c] column <number of column in a graph> -[f] from <a minimal weight>   -[t] to <a maximal weight> -[s] start <index of a point of start> -[e] finish <index of a point of finish>\nRemember:\n input file name defaultly 1.dat\n output file name defaultly 1.dat\n deafault number of a row - 100 (only a natural number can be an arg)\n default number of a column - 100 (only a natural number can be an arg)\n default minimal weight 0.01 (only value > 0)\n default maximal weight 10 (only value >= minimal value)\n start - defaultly a node of index 0 (only an integer number from 0 to (row*column-1)\n finish - defaultly a node of index (row*column-1) (only an integer number from 0 to (row*column-1))\nw");
}
int main (int argc, char **argv) {
	char *input = NULL; 
	char *output = NULL;
	int row = 100;
	int column = 100;
	double from = 0.01;
	double to = 10;
	int start = 1;
	int finish = -1;
	char *program = argv[0];
	int opt;
	while((opt = getopt_long_only(argc, argv, "o:i:r:c:f:t:s:e:",long_options,NULL)) != -1) { // long options have to be done //update: to check
		switch (opt) { 
			case 'o':
				output = optarg;				
				break;
			case 'i':
				input = optarg;
				break;
			case 'r':
				row = atoi(optarg);
				break;
			case 'c':
				column = atoi(optarg);
				break;
			case 'f':
				from = atof(optarg);
				break;
			case 't':
				to = atof(optarg);
				break;
			case 's':
				start = atoi(optarg);
				break;
			case 'e':
				finish = atoi(optarg);
				break;
			default:
				write_usage();
				fprintf(stderr,"%s: Unknown option\n", argv[0]);
				exit(EXIT_FAILURE);
		}
	}
	if (output) {
		printf("Pracuję w trybie generatora - I'm working in a generator mode\n");
		printf("Przesyłam pliki do %s\n",output);
		if(generator(output,row,column,from,to))
			printf("Data saved in %s\n",output);
	}

	if (input) {
		printf("Pracuję w trybie solvera - I'm working in a solver mode\n ");
		printf("Pobieram dane z %s\n", input);
		//if(solver(input, start, finish)) // if finish equals -1 then finish equals column*row-1
		//	;
		
	}
	if (!input && !output) {
		write_usage();
		fprintf(stderr, "%s: Program needs to be started in one of modes (generator or/and solver)\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
