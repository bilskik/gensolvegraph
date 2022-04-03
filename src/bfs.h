#ifndef __BFS_H__
#define __BFS_H__

typedef struct queue {
    int *queue_tab;
    int *visited;
    int size;
    int actual_amount;
} queue_t;

queue_t *queue_init();
int BFS_solver();
int isEmpty(queue_t *queue);
void dequeue(queue_t *queue);
void enqueue(queue_t *queue, int value);
void free_queue(queue_t *queue);

#endif