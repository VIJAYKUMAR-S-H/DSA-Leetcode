#include <stdlib.h>

typedef struct {
    int *queue;
    int front;
    int rear;
} RecentCounter;


/* Create object */
RecentCounter* recentCounterCreate() {

    RecentCounter* obj = (RecentCounter*)malloc(sizeof(RecentCounter));

    obj->queue = (int*)malloc(sizeof(int) * 10000);
    obj->front = 0;
    obj->rear = -1;

    return obj;
}


/* Ping operation */
int recentCounterPing(RecentCounter* obj, int t) {

    // insert new request
    obj->queue[++obj->rear] = t;

    // remove old requests
    while(obj->queue[obj->front] < t - 3000) {
        obj->front++;
    }

    // return number of valid requests
    return obj->rear - obj->front + 1;
}


/* Free memory */
void recentCounterFree(RecentCounter* obj) {
    free(obj->queue);
    free(obj);
}