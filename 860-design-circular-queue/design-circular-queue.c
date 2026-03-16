#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularQueue;


/* Create Circular Queue */
MyCircularQueue* myCircularQueueCreate(int k) {

    MyCircularQueue* obj =
        (MyCircularQueue*)malloc(sizeof(MyCircularQueue));

    obj->arr = (int*)malloc(sizeof(int) * k);
    obj->capacity = k;
    obj->size = 0;
    obj->front = 0;
    obj->rear = -1;

    return obj;
}


/* Insert element */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {

    if (obj->size == obj->capacity)
        return false;   // queue full

    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->arr[obj->rear] = value;
    obj->size++;

    return true;
}


/* Delete element */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {

    if (obj->size == 0)
        return false;   // empty

    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;

    return true;
}


/* Get Front */
int myCircularQueueFront(MyCircularQueue* obj) {

    if (obj->size == 0)
        return -1;

    return obj->arr[obj->front];
}


/* Get Rear */
int myCircularQueueRear(MyCircularQueue* obj) {

    if (obj->size == 0)
        return -1;

    return obj->arr[obj->rear];
}


/* Check Empty */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}


/* Check Full */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;
}


/* Free Memory */
void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}