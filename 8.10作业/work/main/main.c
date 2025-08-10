#include"../include/queue.h"
#include"stdio.h"
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"string.h"
#include "../include/stack.h"
int main() {
    Queue q;
    Queue_init(&q);

    for(int i=0;i<10;i++){
        Queue_in(&q,i);
    }

    Queue_print(&q);

    printf("出队元素: %d\n", Queue_out(&q));
    Queue_print(&q);

    Stack s;
    Stack_init(&s);

    printf("入栈元素：1, 2, 3\n");
    
    Stack_in(&s, 1);
    Stack_in(&s, 2);
    Stack_in(&s, 3);

    int top;
    if (Stack_top(&s, &top)) {
        printf("栈顶元素: %d\n", top);
    } else {
        printf("栈为空，没有栈顶元素\n");
    }

    int pop;
    printf("开始出栈:\n");
    while (Stack_pop(&s, &pop)) {
        printf("弹出元素: %d\n", pop);
    }

    if (Stack_empty(&s)) {
        printf("栈已经空了\n");
    }

    return 0;

}
