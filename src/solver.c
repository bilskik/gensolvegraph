#include "solver.h"
#include "reader.h"
#include "bfs.h"
#include "searcher.h"

#include <stdio.h>
#include <stdlib.h>

points_t *tab;
extern int row_length;
extern int column_length;

void read_and_solve(char *input, int start, int finish)  {

   // file_reader(output);

    if(file_reader(input) == 2) {
        fprintf(stderr, "Sorry, I can't open a file!\n CODE OF ERROR 2:");
    } 
    if(check_graph() == 0)
        printf("Graf jest spojny!\n");
    if(check_graph() == 4)
        fprintf(stderr, "Graph isn't consistent!\n CODE OF ERROR: 4");
    if (finish == -1){
    	finish = row_length*column_length-1;
    }
    printf("FINISH =  %d ", finish);
    printf("WYMIARY =  %d %d\n", row_length, column_length);
    prev_and_weight_t *solved = searcher(start);
    /*int i = finish;
    while(!(start == solved[i].p)) {
        printf("%d  ", i);
	i = solved[i].p;
    }
    */
    /*
    for(int i=0; i<9; i++) {
        for(int s=0; s<4; s++) {
            printf("%d dla: %d : %g\n", tab[i].p,tab[i].tab_neigh[s], tab[i].neigh_value[s]);
            if(tab[i].neigh_value[s] > 100)
                printf("ERROR!\n");
        }
    } 
    */
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