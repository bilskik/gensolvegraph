#ifndef __READER_H__
#define __READER_H__


typedef struct points {
    int p;                      //index of point
    int *tab_neigh;          
    double *neigh_value; 

} points_t;

extern points_t *tab;
int file_reader(char *output);

#endif