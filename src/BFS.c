#include "bfs.h"
#include "solver.h"
#include "reader.h"

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define negative_value -1
#define MAX_SIZE_BOX 5

points_t *tab;
int column_length,row_length;

int isEmpty(queue_t *queue) {
    if(queue->queue_tab[0] == negative_value)
        return 0;
    else
        return 1;
}

void dequeue(queue_t *queue) {
    int i=0;
    while(queue->queue_tab[i] != negative_value) {
        queue->queue_tab[i] = queue->queue_tab[i+1];
        i++;
    }

}
void enqueue(queue_t *queue,int value) {
    int i=0;
    while(queue->queue_tab[i] != negative_value) 
        i++;
    queue->queue_tab[i] = value;

}

queue_t *queue_init() {
    queue_t *queue = malloc(sizeof*queue);
    queue->queue_tab = malloc((column_length*row_length)*sizeof*(queue->queue_tab));
    queue->visited = malloc((column_length*row_length)*sizeof*(queue->visited));
    queue->size = column_length*row_length;
    queue->actual_amount = 0;
    for(int i=0; i<column_length*row_length; i++) {
        queue->queue_tab[i]= negative_value;
        queue->visited[i] = false;
    }
    return queue;
}

void free_queue(queue_t *queue) {
    free(queue->queue_tab);
    free(queue->visited);
    free(queue);
}

int BFS_solver() {
    int tmp;
    int tmp_neigh;
    queue_t *queue = queue_init();
    queue->queue_tab[0] = tab[0].p;
    queue->visited[0] = true;
    #ifdef _BFS
        printf("ACTUAL ELEMENTS IN THE QUEUE: \n");
    #endif
    while(isEmpty(queue)) {                 //main BFS loop
        tmp = queue->queue_tab[0];
        #ifdef _BFS
            int i = 0;
            while(queue->queue_tab[i] != negative_value) {
                printf("%d ",queue->queue_tab[i]);
                i++;
            }     
            printf("\n");
        #endif   
        dequeue(queue);
        for(int i=0; i<MAX_SIZE_BOX; i++) {
            if(tab[tmp].tab_neigh[i] == negative_value)
                continue;
            else {
                if(queue->visited[tab[tmp].tab_neigh[i]] == true)
                    continue;
                else {
                    enqueue(queue, tab[tmp].tab_neigh[i]);
                    queue->visited[tab[tmp].tab_neigh[i]] = true;
                }
            }
        }
            
    }

    for(int i=0; i<row_length*column_length; i++) {
        if(queue->visited[i] == false) {
            free_queue(queue);
            return 4;
        }
    }
#ifdef _BFS
    printf("VISITED: ");
    for(int i=0; i<row_length*column_length; i++) {
        printf("%d, ",queue->visited[i]);
    }
#endif
    free_queue(queue);
    return 0;
}

