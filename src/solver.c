#include "solver.h"
#include "reader.h"

#include <stdio.h>
#include <stdlib.h>



void read_and_solve(char *output) {
    if(file_reader(output) == 1) {
        fprintf(stderr, "Sorry, I can't open a file!");
    }
    
}