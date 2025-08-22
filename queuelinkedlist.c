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

void infixToPostfix(char* infix, char* postfix) {
    int i = 0, k = 0;
    char c;
    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top && peek() != '(')
                postfix[k++] = pop();
            pop(); // remove '('
        } else { // operator
            while (top && precedence(peek()) >= precedence(c))
                postfix[k++] = pop();
            push(c);
        }
    }
    while (top)
        postfix[k++] = pop();
    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
