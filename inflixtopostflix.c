#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 25

struct node {
    char data;
    struct node *next;
};

struct node *top = NULL;

void push(char c) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = c;
    newnode->next = top;
    top = newnode;
}

char pop() {
    if (top == NULL) return '\0';
    struct node *temp = top;
    char c = temp->data;
    top = top->next;
    free(temp);
    return c;
}

char peek() {
    if (top == NULL) return '\0';
    return top->data;
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void reverse(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void infixToPrefix(char* infix, char* prefix) {
    int n = strlen(infix);
    char revInfix[MAX], revPostfix[MAX];
    strcpy(revInfix, infix);
    reverse(revInfix);

    // Swap '(' and ')'
    for (int i = 0; i < n; i++) {
        if (revInfix[i] == '(')
            revInfix[i] = ')';
        else if (revInfix[i] == ')')
            revInfix[i] = '(';
    }

    // Convert reversed infix to postfix
    int i = 0, k = 0;
    char c;
    top = NULL; // Reset stack
    while ((c = revInfix[i++]) != '\0') {
        if (isalnum(c)) {
            revPostfix[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top && peek() != '(')
                revPostfix[k++] = pop();
            pop(); // remove '('
        } else { // operator
            while (top && precedence(peek()) > precedence(c))
                revPostfix[k++] = pop();
            push(c);
        }
    }
    while (top)
        revPostfix[k++] = pop();
    revPostfix[k] = '\0';

    // Reverse postfix to get prefix
    reverse(revPostfix);
    strcpy(prefix, revPostfix);
}

int main() {
    char infix[MAX], prefix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}
