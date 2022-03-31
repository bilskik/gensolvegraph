#include "bfs.h"
#include "solver.h"
#include "reader.h"

#include <stdio.h>
#include <stdlib.h>

#define SIZE 64
 
points_t *tab;

int column_length,row_length;

queue_t *queue_init() {
    queue_t *queue = malloc(sizeof*queue);
    queue->queue_tab = malloc((column_length*row_length)*sizeof*(queue->queue_tab));
    queue->visited = malloc((column_length*row_length)*sizeof*(queue->visited));
    queue->size = SIZE;
    queue->actual_amount = 0;
    return queue;
}

int check_graph() {
    //printf("%d\n", tab[0].p);
    printf("siema: %d, %d\n",row_length,column_length);
    queue_t *queue = queue_init();
    return 0;
}

