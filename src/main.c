//Sorry for my english, a description and an usage to check, chyba że piszemy po polsku?
#include "generator.h"
#include "reader.h"
#include "solver.h"

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

double from;
double to;

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
	int row = 10;
	int column = 10;
	from = 0.01;
	to = 10;
	int start = 0;
	int finish = row*column-1;
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
		printf("I'm working in a generator mode\n");
		printf("I am sending data to %s\n",output);
		if(generator(output,row,column,from,to))
			printf("Data saved in %s\n",output);
	}

	if (input) {
		printf("I'm working in a solver mode\n");
		printf("I'm downloading data from %s\n", input);
		int code = read_and_solve(input, start, finish);
		if(code == 2)
			fprintf(stderr, "Sorry, I can't open a file!\n CODE OF ERROR: 2\n");
		else if(code == 3)
			fprintf(stderr, "Given file has bad format!\n CODE OF ERROR: 3\n");
		else if (code == 4)
			fprintf(stderr, "Graph isn't consistent!\n CODE OF ERROR: 4\n");
		
	}
	if (!input && !output) {
		write_usage();
		fprintf(stderr, "%s: Program needs to be started in one of modes (generator or/and solver)\n, CODE OF ERROR: 1\n", argv[0]);
		
	}
	exit(EXIT_SUCCESS);
}
