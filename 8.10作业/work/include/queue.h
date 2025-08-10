#ifndef __QUEUE_H__
#define __QUEUE_H__
#include"stdio.h"
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"string.h"
#define QUEUE_MAXN 20
typedef struct
{
    int data[QUEUE_MAXN]; // 存放队列元素
    int Front;        // 队首
    int Rear;         // 队尾
} Queue;

// 初始化队列
void Queue_init(Queue* q);

// 判断队列是否为空
int Queue_empty(Queue* q);

// 判断队列是否已满
int Queue_full(Queue* q);

// 入队
void Queue_in(Queue* q, int value);

// 出队
int Queue_out(Queue* q);

// 打印队列
void Queue_print(Queue* q);
#endif