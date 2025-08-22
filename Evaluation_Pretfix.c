#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int size;
} pq;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify_up(pq *q, int idx) {
    if (idx && q->data[(idx - 1) / 2] < q->data[idx]) {
        swap(&q->data[idx], &q->data[(idx - 1) / 2]);
        heapify_up(q, (idx - 1) / 2);
    }
}

void heapify_down(pq *q, int idx) {
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int largest = idx;

    if (left < q->size && q->data[left] > q->data[largest])
        largest = left;
    if (right < q->size && q->data[right] > q->data[largest])
        largest = right;
    if (largest != idx) {
        swap(&q->data[idx], &q->data[largest]);
        heapify_down(q, largest);
    }
}

void insert(pq *q, int value) {
    if (q->size == MAX) {
        printf("Priority Queue Overflow\n");
        return;
    }
    q->data[q->size] = value;
    heapify_up(q, q->size);
    q->size++;
}

int extractMax(pq *q) {
    if (q->size == 0) {
        printf("Priority Queue Underflow\n");
        exit(1);
    }
    int max = q->data[0];
    q->data[0] = q->data[--q->size];
    heapify_down(q, 0);
    return max;
}

int main() {
    pq q;
    q.size = 0;

    insert(&q, 10);
    insert(&q, 30);
    insert(&q, 20);
    insert(&q, 5);

    printf("Max: %d\n", extractMax(&q));
    printf("Max: %d\n", extractMax(&q));
    printf("Max: %d\n", extractMax(&q));
    printf("Max: %d\n", extractMax(&q));

    return 0;
}
