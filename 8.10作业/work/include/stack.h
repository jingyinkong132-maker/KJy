#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int top;  // 栈顶索引，-1表示空栈
} Stack;

// 初始化栈
void Stack_init(Stack *s);

// 判断栈是否为空，空返回1，否则0
int Stack_empty(Stack *s);

// 判断栈是否已满，满返回1，否则0
int Stack_full(Stack *s);

// 入栈，成功返回1，失败返回0
int Stack_in(Stack *s, int value);

// 出栈，成功返回1，失败返回0，出栈值通过指针参数返回
int Stack_pop(Stack *s, int *value);

// 获取栈顶元素，成功返回1，失败返回0，栈顶元素通过指针参数返回
int Stack_top(Stack *s, int *value);

#endif
