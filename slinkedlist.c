#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

struct node* createnode() {
    int ele;
    printf("Enter the data: ");
    scanf("%d", &ele);
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->data = ele;
    return newnode;
}

void insert_start(struct node *newnode) {
    if (head == NULL) {
        head = tail = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void insert_end(struct node *newnode) {
    if (head == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void insert_bypos(struct node *newnode, int pos) {
    if (pos == 0 || head == NULL) {
        insert_start(newnode);
        return;
    }
    struct node *temp = head;
    for (int i = 0; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
    if (newnode->next == NULL)
        tail = newnode;
}

void insert_byvalue(struct node *newnode, int value) {
    struct node *temp = head;
    if (head == NULL || head->data == value) {
        insert_start(newnode);
        return;
    }
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
    if (newnode->next == NULL)
        tail = newnode;
}

void delete_bypos(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    if (pos == 0) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;
        free(temp);
        printf("Node deleted at position 0.\n");
        return;
    }
    for (int i = 0; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position not found.\n");
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp == tail)
        tail = temp->prev;
    free(temp);
    printf("Node deleted at position %d.\n", pos);
}

void delete_end() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head == tail) {
        free(head);
        head = tail = NULL;
        printf("Last node deleted.\n");
        return;
    }
    struct node *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(temp);
    printf("Last node deleted.\n");
}

void delete_start() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;
    free(temp);
    printf("First node deleted.\n");
}

void delete_node(int value) {
    struct node *temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }
    if (temp == head) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;
    } else {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev;
    }
    free(temp);
    printf("Node deleted.\n");
}

void display() {
    struct node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, pos, val;
    struct node *newnode;
    printf("\n1.Insert Start\n2.Insert End\n3.Insert by Position\n4.Insert by Value\n5.Delete by Position\n6.Delete from Start\n7.Delete from End\n8.Delete by Value\n9.Display\n10.Exit\nEnter choice: ");      
    while (1) 
    {   
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                newnode = createnode();
                insert_start(newnode);
                break;
            case 2:
                newnode = createnode();
                insert_end(newnode);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                newnode = createnode();
                insert_bypos(newnode, pos);
                break;
            case 4:
                printf("Enter value after which to insert: ");
                scanf("%d", &val);
                newnode = createnode();
                insert_byvalue(newnode, val);
                break;
            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete_bypos(pos);
                break;
            case 6:
                delete_start();
                break;
            case 7:
                delete_end();
                break;
            case 8:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                delete_node(val);
                break;
            case 9:
                display();
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
