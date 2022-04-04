#include "generator.h"  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generator(char* output, int m, int n, double min, double max, int mode) {
    srand(time(NULL));
    FILE *out = fopen(output,"w");
    int neightbour;
    double value;
    double d = max - min;
    int numberofindexes = m*n;
    fprintf(out,"%d %d\n", m , n);
    for (int i = 0; i < numberofindexes; i++) {
        if(i == 0) { //sd
            neightbour = i + 1;
            value = min+(rand()*d/RAND_MAX);
	    if(mode == 1)
		    value = 0.0;
            fprintf(out," %d : %lf", neightbour, value);
            neightbour = i + n;
            value = min+(rand()*d/RAND_MAX);
	    if(mode == 1)
		    value = 0.0;
            fprintf(out," %d : %lf", neightbour, value);
        } 
        else if(i == n-1){//as
            neightbour = i - 1;
            value = min+(rand()*d/RAND_MAX);
	    if(mode == 1)
		    value = 0.0;
            fprintf(out," %d : %lf", neightbour, value);
            neightbour = i + n;
            value = min+(rand()*d/RAND_MAX);
	    if(mode == 1)
		    value = 0.0;
            fprintf(out," %d : %lf", neightbour, value);
        }
        else if (i == (m-1)*n) {//wd
            neightbour = i + 1;
            value = min+(rand()*d/RAND_MAX);
	    	if(mode == 1)
			value = 0.0;
            fprintf(out," %d : %lf", neightbour, value);
            neightbour = i - n;
            value = min+(rand()*d/RAND_MAX);
	    if(mode == 1)
		    value = 0.0;
            fprintf(out," %d : %lf", neightbour, value);
        }
        else if (i == ((m*n)-1)){//aw
            neightbour = i - 1;
            value = min+(rand()*d/RAND_MAX);
	    	if(mode == 1) 
			value = 0.0;
            fprintf(out," %d : %lf", neightbour, value);
            neightbour = i - n;
            value = min+(rand()*d/RAND_MAX);
	    	if(mode == 1)
			value = 0.0;
            fprintf(out," %d : %lf", neightbour, value);
        }
        else if((i > 0)&&(i < n-1)) {//asd
            neightbour = i + 1;
            value = min+(rand()*d/RAND_MAX);
	    if(mode == 1)
		    value = 0.0;
            fprintf(out," %d : %lf", neightbour, value);
            neightbour = i + n;
            value = min+(rand()*d/RAND_MAX);
	    	if(mode == 1);
			value = 0.0;
            fprintf(out," %d : %lf", neightbour, value);
            neightbour = i - 1;
            value = min+(rand()*d/RAND_MAX);
	    	if(mode == 1)
			value = 0.0;
            fprintf(out," %d : %lf", neightbour, value);
        }
        else if((i > (m-1)*n) && (i < m*n-1) ){//wad
            neightbour = i + 1;
            value = min+(rand()*d/RAND_MAX);
	    	if(mode == 1)
			value = 0.0;
            fprintf(out," %d : %lf", neightbour, value);
            neightbour = i - n;
            value = min+(rand()*d/RAND_MAX);
	    	if(mode == 1)
			value = 0.0;
            fprintf(out," %d : %lf", neightbour, value);
            neightbour = i - 1;
            value = min+(rand()*d/RAND_MAX);
	    	if(mode == 1)
			value = 0.0;
            fprintf(out," %d : %lf", neightbour, value);
        }
        else if((i%n) == 0){//dsw
            neightbour = i + 1;
            value = min+(rand()*d/RAND_MAX);
	    	if(mode == 1)
			value = 0.0;
            fprintf(out," %d : %lf", neightbour, value);
            neightbour = i - n;
            value = min+(rand()*d/RAND_MAX);
	    	if(mode == 1)
			value = 0.0;
            fprintf(out," %d : %lf", neightbour, value);
            neightbour = i + n;
            value = min+(rand()*d/RAND_MAX);
	    	if(mode == 1)
			value = 0.0;
            fprintf(out," %d : %lf", neightbour, value);
        }
        else if (((i+1)%n) == 0){//asw
            neightbour = i + n;
            value = min+(rand()*d/RAND_MAX);
            fprintf(out," %d : %lf", neightbour, value);
            neightbour = i - n;
            value = min+(rand()*d/RAND_MAX);
            fprintf(out," %d : %lf", neightbour, value);
            neightbour = i - 1;
            value = min+(rand()*d/RAND_MAX);
            fprintf(out," %d : %lf", neightbour, value);
        }
        else {//wasd
            neightbour = i + 1;
            value = min+(rand()*d/RAND_MAX);
            fprintf(out," %d : %lf", neightbour, value);
            neightbour = i - n;
            value = min+(rand()*d/RAND_MAX);
            fprintf(out," %d : %lf", neightbour, value);
            neightbour = i - 1;
            value = min+(rand()*d/RAND_MAX);
            fprintf(out," %d : %lf", neightbour, value);
            neightbour = i + n;
            value = min+(rand()*d/RAND_MAX);
            fprintf(out," %d : %lf", neightbour, value);
        }
        fprintf(out, "\n");
    }
    fclose(out);
    return 0;

}
