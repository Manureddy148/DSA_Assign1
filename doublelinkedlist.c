#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

struct node* createnode() {
    int ele;
    printf("Enter the data: ");
    scanf("%d", &ele);
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->data = ele;
    return newnode;
}

void push() {
    struct node *newnode = createnode();
    newnode->next = top;
    top = newnode;
    printf("Pushed %d onto stack.\n", newnode->data);
}

void pop() {
    if (top == NULL) {
        printf("Stack underflow.\n");
        return;
    }
    struct node *temp = top;
    printf("Popped %d from stack.\n", temp->data);
    top = top->next;
    free(temp);
}

void display() {
    struct node *temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter choice: ");
    while (1) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
