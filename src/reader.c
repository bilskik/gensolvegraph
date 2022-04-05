#include "reader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_BOX 5
#define MAX_SIZE_LINE 100
#define negative_value -1

points_t *tab;
int row_length;
int column_length;

int file_reader(char *filename) {  

    int j = 0;
    int k = 0;
    int iter = 0;
    int keeper = 0;
    int line = 0;
    int i = 0;
    int index = 0;
    int multiplier = 2;
    FILE *in = fopen(filename, "r");

    if(in == NULL) 
        return 2;

    fscanf(in,"%d %d", &row_length,&column_length);
    if( column_length < 1 || row_length < 1) 
        return 3;
    tab = malloc(row_length*column_length*sizeof*tab);
    char *bufor = malloc(MAX_SIZE_LINE*sizeof*bufor);
  

    while(fgets(bufor,MAX_SIZE_LINE, in) != NULL) {  //reading lines
        
        if(line == 0) { 
            line++;
            continue;
        }
        tab[index].tab_neigh = malloc(MAX_SIZE_BOX*sizeof*tab[index].tab_neigh);
        tab[index].neigh_value = malloc(MAX_SIZE_BOX*sizeof*tab[index].neigh_value);
        for(int i=0; i<MAX_SIZE_BOX; i++) {
            tab[index].tab_neigh[i] = -1;
            tab[index].neigh_value[i] = -1;
        }

        tab[iter].p = index;
       
        char *tmp_tab = malloc(MAX_SIZE_LINE*sizeof*tmp_tab);
        int check = 0;
        int tmp_1 = 0;
        int tmp_2 = 0;
        j = 0;
        int f;
        for(int i=0; i<MAX_SIZE_LINE; i++) {

            f = i+1;
            if(bufor[i] == 32 && bufor[f] == 32) {
                continue;
            }
            if(bufor[0] == ' ' && check == 0) {
                check = 1;
                continue;
            }
     

            if(bufor[i] >= '0' && bufor[i] <=  '9' && keeper == 0) {
                tmp_tab[j++] = bufor[i];
                tmp_1 = 1;
                continue;
            }
            else if(keeper == 0 && tmp_1 == 1) {
                tmp_tab[j++] = '\0';
                tab[iter].tab_neigh[k] = atoi(tmp_tab);  
                for(int h=0; h<j; h++) {
                    tmp_tab[h] = '\0';
                }
                keeper = 1;
                j = 0; 
                tmp_1 = 0;
                continue;
            }
            if((bufor[i] >= '0' && bufor[i] <= '9' && keeper == 1) || bufor[i] == '.') {
                tmp_tab[j++] = bufor[i]; 
                tmp_2 = 1;
                continue;
            }
            else if (keeper == 1 && tmp_2 == 1) {
                tmp_tab[j++] = '\0';
                tab[iter].neigh_value[k] = atof(tmp_tab);
                for(int h=0; h<j; h++) {
                    tmp_tab[h] = '\0';
                }
                j = 0;
                keeper = 0;
                tmp_2 = 0;
                k++;
               
                continue;
            }

           
        }
        for(int i=0; i<MAX_SIZE_LINE; i++)
            bufor[i] = ' ';
        free(tmp_tab);
        k = 0;
        iter++;
        index++;
    }
   for(int i=0; i<row_length*column_length; i++) {
        for(int s=0; s<MAX_SIZE_BOX; s++) {
            if(tab[i].neigh_value[s] == 0) {
                tab[i].neigh_value[s] = negative_value;
                tab[i].tab_neigh[s] = negative_value;
            }
            if((tab[i].neigh_value[s] == negative_value && tab[i].tab_neigh[s] !=  negative_value) || 
            (tab[i].neigh_value[s] != negative_value && tab[i].tab_neigh[s] ==  negative_value)) {
                free(bufor);
                fclose(in);
                return 3;
            }
        }
    } 
#ifdef _READER
    for(int i=0; i<row_length*column_length; i++) {
        for(int j=0; j<MAX_SIZE_BOX; j++) {
            if(tab[i].tab_neigh[j] != negative_value)
                printf("%d : %g",tab[i].tab_neigh[j],tab[i].neigh_value[j]);
        }
        printf("\n");
    }
#endif
    free(bufor);
    fclose(in);
    return 0;
}
