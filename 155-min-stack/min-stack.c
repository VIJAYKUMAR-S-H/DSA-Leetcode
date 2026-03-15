#include <stdlib.h>

typedef struct {
    int stack[10000];
    int minStack[10000];
    int top;
} MinStack;

/* initialize stack */
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->top = -1;
    return obj;
}

/* push element */
void minStackPush(MinStack* obj, int val) {

    obj->top++;
    obj->stack[obj->top] = val;

    if(obj->top == 0 || val <= obj->minStack[obj->top-1])
        obj->minStack[obj->top] = val;
    else
        obj->minStack[obj->top] = obj->minStack[obj->top-1];
}

/* pop element */
void minStackPop(MinStack* obj) {
    if(obj->top >= 0)
        obj->top--;
}

/* get top element */
int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

/* get minimum element */
int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->top];
}

/* free memory */
void minStackFree(MinStack* obj) {
    free(obj);
}