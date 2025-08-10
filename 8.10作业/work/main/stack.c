#include "../include/stack.h"

void Stack_init(Stack *s) {
    s->top = -1;
}

int Stack_empty(Stack *s) {
    return s->top == -1;
}

int Stack_full(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

int Stack_in(Stack *s, int value) {
    if (Stack_full(s)) {
        return 0; // 栈满，入栈失败
    }
    s->data[++(s->top)] = value;
    return 1;
}

int Stack_pop(Stack *s, int *value) {
    if (Stack_empty(s)) {
        return 0; // 栈空，出栈失败
    }
    *value = s->data[(s->top)--];
    return 1;
}

int Stack_top(Stack *s, int *value) {
    if (Stack_empty(s)) {
        return 0; // 栈空，无栈顶元素
    }
    *value = s->data[s->top];
    return 1;
}
