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
	{"mode",required_argument, 0, 'm'},
    {0, 0, 0, 0}
};

void write_usage(){
printf("Usage:\n\t-[o] out <output file> -in [i] <input file> -[r] row <number of rows in a graph> -[c] column <number of column in a graph> -[f] from <a minimal weight>   -[t] to <a maximal weight> -[s] start <index of a point of start> -[e] finish <index of a point of finish> -[m] mode <0 or 1>\nRemember:\n input file name defaultly 1.dat\n output file name defaultly 1.dat\n deafault number of a row - 100 (only a natural number can be an arg)\n default number of a column - 100 (only a natural number can be an arg)\n default minimal weight 0.01 (only value > 0)\n default maximal weight 10 (only value >= minimal value)\n start - defaultly a node of index 0 (only an integer number from 0 to (row*column-1)\n finish - defaultly a node of index (row*column-1) (only an integer number from 0 to (row*column-1))\nmode - 0 makes connected graph, 1 makes inconsistent graph\n");
}
int main (int argc, char **argv) {
	char *input = NULL; 
	char *output = NULL;
	int row = 10;
	int column = 10;
	from = 0.01;
	to = 10;
	int start = 0;
	int finish = -1;
	int mode = 0;
	char *program = argv[0];
	int opt;
	while((opt = getopt_long_only(argc, argv, "o:i:r:c:f:t:s:e:m:",long_options,NULL)) != -1) {  	//flags are enetered
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
			case 'm':
				mode = atoi(optarg);
				break;
			default:
				write_usage();
				fprintf(stderr,"%s: Unknown option\n", argv[0]);
				return 1;
		}
	}
	if((row < 0) || (column < 0) || (from < 0) || (to < 0) || (to < from) ) {
		fprintf(stderr,"Entering values are incorrect!\n");
		return 5;	
	}
	
	if(mode != 0 && mode != 1){
		write_usage();
		fprintf(stderr,"Bad mode\n");
		return 5;

	}
	if (output) {							//output mode
		printf("I'm working in a generator mode\n");
		printf("I am sending data to %s\n",output);
		if(generator(output,row,column,from,to,mode))
			printf("Data saved in %s\n",output);
	}

	if (input) { 							//input mode
		printf("I'm working in a solver mode\n");
		printf("I'm downloading data from %s\n", input);
		int code = read_and_solve(input, start, finish);
		if(code == 2) {
			fprintf(stderr, "Sorry, I can't open a file!\n");
			return 2;
		}
		else if(code == 3) {
			fprintf(stderr, "Given file has bad format!\n");
			return 3;
		}
		else if (code == 4) {
			fprintf(stderr, "Graph isn't consistent!\n");
			return 4;
		}
		else if (code == 6) {
			fprintf(stderr, "Start or/and finish beyond the graph!\n");
			return 6;
		}

	}
	if (!input && !output) {
		write_usage();
		fprintf(stderr, "%s: Program needs to be started in one of modes (generator or/and solver)\n", argv[0]);
		return 1;
		
	}
	exit(EXIT_SUCCESS);
}
