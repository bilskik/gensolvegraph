#include "reader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define MAX_SIZE_LINE 100

void file_reader(char *filename) {

    FILE *in = fopen(filename, "r");
    int row_length;
    int column_length;

    fscanf(in,"%d %d", &row_length,&column_length);


    //points_t *tab = malloc((row_length*column_length)*sizeof*tab);
    points_t tab[10000];
    char *bufor = malloc(MAX_SIZE_LINE*sizeof*bufor);
    int j = 0;
    int k = 0;
    int iter = 0;
    int keeper = 0;
    int line = 0;
    int i = 0;
    int index = 0;


    while(fgets(bufor,100, in) != NULL) {
        
        if(line == 0) { 
            line++;
            continue;
        }

        tab[iter].p = index;
       
        char *tmp_tab = malloc(100*sizeof*tmp_tab);
        int check = 0;
        int tmp_1 = 0;
        int tmp_2 = 0;
        j = 0;
        for(int i=0; i<100; i++) {
         
            if(bufor[0] == ' ' && check == 0) {
                check = 1;
                continue;
            }
     
            //printf("keeper == %d , bufor == %c\n", keeper, bufor[i]);
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
                k++;
                keeper = 0;
                tmp_2 = 0;
                continue;
            }

            if(bufor[i] == 32) {
               continue;
            }
            
        }
        free(tmp_tab);
        k = 0;
        iter++;
        index++;
    }

    for(int i=0; i<25; i++) {
        for(int s=0; s<4; s++)
            printf("%d dla: %d : %g\n", tab[i].p,tab[i].tab_neigh[s], tab[i].neigh_value[s]);
    }
    fclose(in);
   
}
