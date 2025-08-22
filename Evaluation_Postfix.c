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

int evalPrefix(char* prefix) {
    int len = strlen(prefix);
    for (int i = len - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isspace(c)) continue;
        if (isdigit(c)) {
            push(c - '0');
        } else {
            int val1 = pop();
            int val2 = pop();
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
    char prefix[MAX];
    printf("Enter prefix expression: ");
    scanf("%s", prefix);
    int result = evalPrefix(prefix);
    printf("Result: %d\n", result);
    return 0;
}
