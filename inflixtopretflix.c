#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int evalPostfix(char* postfix) {
    int i = 0;
    char c;
    while ((c = postfix[i++]) != '\0') {
        if (isdigit(c)) {
            push(c - '0'); 
        } else {
            int val2 = pop();
            int val1 = pop();
            switch (c) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                case '^': {
                    int res = 1;
                    for (int j = 0; j < val2; j++) res *= val1;
                    push(res);
                    break;
                }
            }
        }
    }
    return pop();
}

int main() {
    char postfix[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    int result = evalPostfix(postfix);
    printf("Result: %d\n", result);
    return 0;
}
