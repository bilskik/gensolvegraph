#include "reader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// testing version of reader

#define MAX_SIZE_LINE 1000

void file_reader(char * output) {

    FILE *in = fopen(output, "r");
    int row_length;
    int column_length;

    fscanf(in,"%d %d", &row_length,&column_length);


    points_t tab[10000];

    char *bufor = malloc(100*sizeof*bufor);
    char tmp_tab[100] ={'0'};
    char tmp_2_tab[100];
    int j = 0;
    int k = 0;
    int c = 0;
    int iter = 0;
    int keeper = 0;
    int linia = 0;


    while(fgets(bufor, 100, in) != NULL) {
        
        //printf("%s", bufor);
        tab[iter].p = linia;

        for(int i=0; i<strlen(bufor); i++) {
            
            
            if(bufor[0] == ' ') {
                continue;
            }

            if (bufor[i] == ':') {
                keeper = 1;
            }

            printf("%d\n", keeper);
            printf("%c", bufor[i]);
            if(bufor[i] >= '0' && bufor[i] <= '9' && keeper == 0) {
                printf("siema");
                tmp_tab[j++] = bufor[i];
                printf("%s\n", tmp_tab); 
                
            }
            else if(keeper == 0) {
                tab[iter].tab_neigh[k] = atoi(tmp_tab);
                j = 0;
                while(tmp_tab[j++] != '0') 
                    tmp_tab[j] = '0';
                j = 0; 
            }

            if((bufor[i] >= '0' && bufor[i] <= '9' && keeper == 1) || bufor[i] == '.') {
                tmp_tab[j++] = bufor[i]; 
            }
            else if (keeper == 1) {
                tab[iter].neigh_value[k] = atof(tmp_tab);
                j = 0;
                 while(tmp_tab[j++] != '0') 
                    tmp_tab[j] = '0';
                j = 0;
                k++;
            }

           
            
        }
        k = 0;
        iter++;
        linia++;
    }

    for(int i=0; i<25; i++) {
        printf("%d dla: %d : %g\n", i,tab[i].tab_neigh[0], tab[i].neigh_value[0]);
    }

}