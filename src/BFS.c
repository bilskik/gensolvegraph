#include "bfs.h"
#include "solver.h"
#include "reader.h"

#include <stdio.h>
#include <stdlib.h>

#define SIZE 64
#define true 1
#define false 0
#define negative_value -1

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
    queue->size = SIZE;
    queue->actual_amount = 0;
    for(int i=0; i<column_length*row_length; i++) {
        queue->queue_tab[i]= negative_value;
        queue->visited[i] = false;
    }
    return queue;
}

int check_graph() {
    int tmp;
    int tmp_neigh;
    queue_t *queue = queue_init();
    queue->queue_tab[0] = tab[0].p;
    queue->visited[0] = true;
    while(isEmpty(queue)) {
        tmp = queue->queue_tab[0];        
        dequeue(queue);
        for(int i=0; i<4; i++) {
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
        if(queue->visited[i] == false)
            return 1;
    }
    return 0;
}

