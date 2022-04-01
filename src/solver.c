#include "solver.h"
#include "reader.h"
#include "bfs.h"

#include <stdio.h>
#include <stdlib.h>

points_t *tab;
extern int row_length;
extern int column_length;

void read_and_solve(char *output) {

   // file_reader(output);

    if(file_reader(output) == 1) {
        fprintf(stderr, "Sorry, I can't open a file!");
    } 
    if(check_graph() == 0)
        printf("Graf jest spojny!\n");
    else 
        printf("graf nie jest spojnt!\n");
    /*
    for(int i=0; i<9; i++) {
        for(int s=0; s<4; s++) {
            printf("%d dla: %d : %g\n", tab[i].p,tab[i].tab_neigh[s], tab[i].neigh_value[s]);
            if(tab[i].neigh_value[s] > 100)
                printf("ERROR!\n");
        }
    } 
    */
    
}