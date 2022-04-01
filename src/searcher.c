#include "searcher.h"
#include "reader.h"
#include "solver.h"

#include <stdlib.h>
#include <float.h>

int row_length;
int column_length;

prev_and_weight_t *searcher(int start){
	start = 0;
    int index = row_length * column_length-1;

    prev_and_weight_t *tab_value = malloc (index*sizeof(prev_and_weight_t));
    int S[index];
    for (int i = 0; i < index; i++) {
        S[i] = 0;
    }
    int Q[index];	 
    for (int i = 0; i < index; i++) {
        Q[i] = 1;
    }
    for(int i = 0; i < index; i++)
        tab_value[i].d = DBL_MAX;
    tab_value[start].d = 0; 	
    for (int i = 0; i < index; i++) {
        tab_value[i].p = -1;
    }
int isboolean = 1;
    while (isboolean) {
	    double tmp = DBL_MAX;
    int j;
    	for(int i = 0; i < index; i++) 
       		if(tab_value[i].d <= tmp && Q[i] != 0 ){
			tmp = tab_value[i].d;
			j = i;
		}
	S[j] = Q[j];
	Q[j] = 0;			

    	int i = 0;
	while( tab[j].tab_neigh[i] != -1){
		if(Q[tab[j].p] && tab_value[tab[j].tab_neigh[i]].d > tab_value[tab[j].p].d + tab[j].neigh_value[i]){
			tab_value[tab[j].tab_neigh[i]].d = tab_value[tab[j].p].d + tab[j].neigh_value[i];
			tab_value[tab[j].tab_neigh[i]].d = tab[j].p;
			
		}
		i++;
	}

    isboolean = 0;
    for(int i = 0; i < index; i++) 
        if(Q[i]) {
            isboolean = 1;
            break;        
        }    
    }
    return tab_value;
}
