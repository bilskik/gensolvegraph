

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct points {
    int p;                      //index of point
    int tab_neigh[4];          
    double neigh_value[4]; 

}points_t;
// testing version of reader

#define MAX_SIZE_LINE 1000

int main(int argc, char **argv) {

    FILE *in = fopen(argv[1], "r");
    int row_length;
    int column_length;

    //fscanf(in,"%d %d", &row_length,&column_length);


    points_t tab[10000];

    char *bufor = malloc(100*sizeof*bufor);
    //char *tmp_tab = malloc(100*sizeof*tmp_tab);
    char tmp_2_tab[100];
    char c;
    int j = 0;
    int k = 0;
    int iter = 0;
    int keeper = 0;
    int linia = 0;
    int i=0;


    while(fgets(bufor,100, in) != NULL) {
        
        tab[iter].p = linia;
       
        char *tmp_tab = malloc(100*sizeof*tmp_tab);

        for(int i=0; i<100; i++) {
           // printf("%c", bufor[i]);
             //printf("bufor[0] %c", bufor[1]);
            //printf("tu %c", bufor[i]);
            
            if(bufor[i] == 32) {
               continue;
            }

            if (bufor[i] == ':') {
               keeper = 1;
               continue;
            }
            //printf("keeper = %d\n", keeper);
           // printf("%c", bufor[i]);
            //printf("%c", bufor[i]);
            if(bufor[i] >= '0' && bufor[i] <=  '9' && keeper == 0) {
                //printf("%c  ", bufor[i]);
                tmp_tab[j] = bufor[i];
                printf("%c\n", tmp_tab[j++]); 
                
            }
            else if(keeper == 0) {
                //tmp_tab[j++] = '\0';
                printf("tu: %c\n", tmp_tab[0]);
                for(int h=0; h<j; h++)
                    ;//printf("przed %c\n", tmp_tab[h]);
                //printf("po %s\n", tmp_tab);
                
                //tab[iter].tab_neigh[k] = atoi(tmp_tab);
                //printf("in tab: %d\n",tab[iter].tab_neigh[k]);
                //printf("j == %d", j);
                int tmp = atoi(tmp_tab);
                //printf("tmp == %d , tmp_tab == %s\n", tmp, tmp_tab);
                for(int h=0; h<j; h++) {
                    printf("siema: %c\n", tmp_tab[h]);
                    tmp_tab[h] = '\0';
                }
                j = 0; 
            }
            int f = i;
            if((bufor[i] >= '0' && bufor[i] <= '9' && keeper == 1) || bufor[i] == '.') {
                tmp_tab[j++] = bufor[i]; 
                //printf("%c", tmp_tab[j++]);
            }
            else if (keeper == 1 && bufor[i] != ' ') {
                tmp_tab[j++] = '\0';
                tab[iter].neigh_value[k] = atof(tmp_tab);
                for(int h=0; h<j; h++) {
                    tmp_tab[h] = '\0';
                }
                j = 0;
                k++;
                keeper = 0;
            }

           
            
        }
        free(tmp_tab);
        k = 0;
        iter++;
        linia++;
    }

    for(int i=0; i<25; i++) {
        printf("%d dla: %d : %g\n", i,tab[i].tab_neigh[0], tab[i].neigh_value[0]);
    }
    fclose(in);
    return 0;
}
