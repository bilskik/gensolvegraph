#include "searcher.h"
#include "reader.h"
#include "solver.h"

#include <stdlib.h>
#include <float.h>
#include <stdio.h>

int row_length;
int column_length;

prev_and_weight_t *searcher(int start){
#ifdef _DEBUG 
	printf("Start searcher = %d\n",start); 
#endif
    int index = row_length * column_length;
#ifdef _DEBUG
    printf("Wymiary searcher %d  %d \n", row_length, column_length);
#endif
    prev_and_weight_t *tab_value = malloc (index*sizeof(prev_and_weight_t));
    int Q[index];	 
    for (int i = 0; i < index; i++) {
        Q[i] = 1; 			
    }
#ifdef _DEBUG
    for (int i = 0; i < index; i++) {
	printf("%d ", Q[i]);
    }
#endif
    for(int i = 0; i < index; i++)          //structure initalization
        tab_value[i].d = DBL_MAX;
    tab_value[start].d = 0; 	
    for (int i = 0; i < index; i++) {
        tab_value[i].p = -1;
    }
#ifdef _DEBUG    
    printf("\n");
    printf("Waga|Poprzednik ");

    for (int i = 0; i < index; i++) {      
	    if(start == i) 
		    printf("Start:  ");
	    printf(" %f | %d \n",tab_value[i].d,tab_value[i].p);
    }
#endif
    int isboolean = 1;
    while (isboolean) {   //main djikstra loop
	double tmp = DBL_MAX;
    	int j;
    	for(int i = 0; i < index; i++) 
       		if(tab_value[i].d <= tmp && Q[i] != 0 ){
			tmp = tab_value[i].d;
			j = i;
		}
#ifdef _DEBUG
	printf("%d\n", j);	
#endif
    	int i = 0;
	while( tab[j].tab_neigh[i] != -1){
		if(Q[j] && tab_value[tab[j].tab_neigh[i]].d > tab_value[j].d + tab[j].neigh_value[i]){
			tab_value[tab[j].tab_neigh[i]].d = tab_value[j].d + tab[j].neigh_value[i];
			tab_value[tab[j].tab_neigh[i]].p = tab[j].p;
			
		}
		i++;
	}
	Q[j] = 0;

    isboolean = 0;
    for(int i = 0; i < index; i++) 
        if(Q[i]) {
            isboolean = 1;
            break;        
        }    
    }
#ifdef _DEBUG
    printf("Wierzchołek | Wartość | poprzednik\n");
    for(int i = 0; i < index; i++) 
	    printf("  %d  | %f | %d  \n", i , tab_value[i].d, tab_value[i].p);
#endif
    return tab_value;
}

