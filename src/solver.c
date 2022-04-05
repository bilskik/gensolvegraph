#include "solver.h"
#include "reader.h"
#include "bfs.h"
#include "searcher.h"

#include <stdio.h>
#include <stdlib.h>

points_t *tab;
extern int row_length;
extern int column_length;
extern double from,to;

int read_and_solve(char *input, int start, int finish)  {

    int error_file_code = file_reader(input);
    if(error_file_code == 2) 
        return 2;
    else if (error_file_code == 3) {
        free_values(NULL);
        return 3;
    }

    int error_graph_code = BFS_solver();
    if(error_graph_code == 0)
        printf("Graph is consistent!\n");

    if(error_graph_code == 4) {
        free_values(NULL);
        return 4;
    }

    if (finish == -1){
    	finish = row_length*column_length-1;
    }
    if(start < 0 || start >= row_length*column_length || finish < 0 || finish >= row_length*column_length) {
        free_values(NULL);
	   return 6; 
    }

#if _DEBUG 

    printf("FINISH =  %d ", finish);
    printf("WYMIARY =  %d %d\n", row_length, column_length);
#endif

    prev_and_weight_t *solved = searcher(start);
    int i = finish;
    printf("Way from start to finish: from %d to %d\n", start, finish);
        while(solved[i].p != -1) {
        printf("%d <- ", i);
	i = solved[i].p;
    }
	printf("%d\n",start);
	printf("Value: %f\n", solved[finish].d);
    free_values(solved);
}

void free_values(prev_and_weight_t *solved) {
    for(int i=0; i<row_length*column_length; i++) {
        free(tab[i].tab_neigh);
        free(tab[i].neigh_value);

    }
    free(tab);
    free(solved);
}
