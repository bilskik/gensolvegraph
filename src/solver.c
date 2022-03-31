#include "solver.h"
#include "reader.h"

#include <stdio.h>
#include <stdlib.h>

points_t *tab;
extern int row_length;
extern int column_length;

void read_and_solve(char *output) {

    file_reader(output);

    if(file_reader(output) == 1) {
        fprintf(stderr, "Sorry, I can't open a file!");
    } 
    /*
    printf("%d %d\n", row_length,column_length);
    for(int i=0; i<9; i++) {
        for(int s=0; s<4; s++) {
            printf("%d dla: %d : %g\n", tab[i].p,tab[i].tab_neigh[s], tab[i].neigh_value[s]);
            if(tab[i].neigh_value[s] > 100)
                printf("ERROR!\n");
        }
    } 
    */
}