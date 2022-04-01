#ifndef __BFS_H__
#define __BFS_H__

typedef struct queue {
    int *queue_tab;
    int *visited;
    int size;
    int actual_amount;
} queue_t;

queue_t *queue_init();
int check_graph();
int isEmpty(queue_t *queue);
void dequeue(queue_t *queue);
void enqueue(queue_t *queue, int value);

#endif