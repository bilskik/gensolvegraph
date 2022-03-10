#ifndef __READER_H__
#define __READER_H__

typedef struct points {
    int p;                      //index of point
    int tab_neigh[4];          
    double neigh_value[4]; 

}points_t;

void file_reader(char *output);

#endif