

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
    char tmp_tab[100] ={'0'};
    char tmp_2_tab[100];
    char c;
    int j = 0;
    int k = 0;
    int iter = 0;
    int keeper = 0;
    int linia = 0;
    int i=0;

    while(1) {
        
        j = 0;

        do {
            c = fgetc(in);
            if(c == EOF)
                break;
            bufor[j] = c;
            // printf("%c", bufor[j]);
            j++;
        }        
        while(c != '\n');

       // printf(" j == %d",j);
        tab[iter].p = linia;
       
        //printf("\n");
        for(int i=0; i<j; i++) {
             //printf("bufor[0] %c", bufor[1]);
            //printf("tu %c", bufor[i]);
            
          //  if(bufor[0] == 32) {
         //       continue;
         //   }

            //if (bufor[i] == ':') {
           //     keeper = 1;
          //  }
            //printf("  %c", bufor[i]);
            printf("%c", bufor[i]);
            
            if(bufor[i] >= 48 && bufor[i] <=  57 && keeper == 0) {
                printf("siema %c", bufor[i]);
                tmp_tab[j++] = bufor[i];
                //printf("%s\n", tmp_tab); 
                
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
    fclose(in);
    return 0;
}
