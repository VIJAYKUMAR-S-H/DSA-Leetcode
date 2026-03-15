#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calPoints(char **ops, int opsSize) {

    int stack[1000];
    int top = -1;

    for(int i = 0; i < opsSize; i++) {

        if(strcmp(ops[i], "C") == 0) {
            top--;   // remove last score
        }

        else if(strcmp(ops[i], "D") == 0) {
            stack[++top] = 2 * stack[top];
        }

        else if(strcmp(ops[i], "+") == 0) {
            int sum = stack[top] + stack[top-1];
            stack[++top] = sum;
        }

        else {
            int val = atoi(ops[i]); // convert string to integer
            stack[++top] = val;
        }
    }

    int total = 0;

    for(int i = 0; i <= top; i++) {
        total += stack[i];
    }

    return total;
}