#include"../include/queue.h"
#include"stdio.h"
#include"stdio.h"
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"string.h"


void Queue_init(Queue* q) {
    q->Front = 0;
    q->Rear = 0;
}

int Queue_empty(Queue* q) {
    return q->Front == q->Rear;
}

int Queue_full(Queue* q) {
    return ((q->Rear + 1) % QUEUE_MAXN) == q->Front;
}

void Queue_in(Queue* q, int value) {
    if (Queue_full(q)) {
        printf("队列已满，无法入队\n");
        return;
    }
    q->data[q->Rear] = value;
    q->Rear = (q->Rear + 1) % QUEUE_MAXN;
}

int Queue_out(Queue* q) {
    if (Queue_empty(q)) {
        printf("队列为空，无法出队\n");
        return -1;
    }
    int value = q->data[q->Front];
    q->Front = (q->Front + 1) % QUEUE_MAXN;
    return value;
}

void Queue_print(Queue* q) {
    if (Queue_empty(q)) {
        printf("队列为空\n");
        return;
    }
    printf("队列内容: ");
    int i = q->Front;
    while (i != q->Rear) {
        printf("%d ", q->data[i]);
        i = (i + 1) % QUEUE_MAXN;
    }
    printf("\n");
}
