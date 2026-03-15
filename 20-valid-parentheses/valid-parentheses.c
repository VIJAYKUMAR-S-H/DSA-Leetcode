

bool isValid(char* s) {

    char stack[10000];
    int top = -1;

    for(int i = 0; s[i] != '\0'; i++){

        char ch = s[i];

        // Opening brackets
        if(ch == '(' || ch == '{' || ch == '['){
            stack[++top] = ch;
        }

        // Closing brackets
        else{

            if(top == -1)
                return false;

            char temp = stack[top--];

            if((ch == ')' && temp != '(') ||
               (ch == '}' && temp != '{') ||
               (ch == ']' && temp != '[')){
                return false;
            }
        }
    }

    return top == -1;
}
    
