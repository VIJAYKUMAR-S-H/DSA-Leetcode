#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100

typedef struct {
    int q1[SIZE];
    int front, rear;
} MyStack;

MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->front = obj->rear = -1;
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    obj->q1[++obj->rear] = x;
}

int myStackPop(MyStack* obj) {
    return obj->q1[obj->rear--];
}

int myStackTop(MyStack* obj) {
    return obj->q1[obj->rear];
}

bool myStackEmpty(MyStack* obj) {
    return obj->rear == -1;
}

void myStackFree(MyStack* obj) {
    free(obj);
}