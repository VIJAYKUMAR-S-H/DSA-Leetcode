#include <stdio.h>
#include <string.h>

char* removeDuplicates(char* s) {

    int n = strlen(s);

    char stack[n];
    int top = -1;

    for(int i = 0; i < n; i++) {

        if(top != -1 && stack[top] == s[i]) {
            top--;   // remove duplicate
        }
        else {
            stack[++top] = s[i];
        }
    }

    stack[top+1] = '\0';

    char *result = (char*)malloc((top+2)*sizeof(char));
    strcpy(result, stack);

    return result;
}