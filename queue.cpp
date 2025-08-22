#include <iostream>
using namespace std;

struct PriorityQueue {
    int a[5];
    int n;
    int size;
    PriorityQueue() : n(5), size(0) {}
} pq;

class Operation {
public:
    void insert(int ele) {
        if (pq.size == pq.n) {
            cout << "Priority Queue is full" << endl;
            return;
        }
        int i = pq.size - 1;
        while (i >= 0 && pq.a[i] < ele) {
            pq.a[i + 1] = pq.a[i];
            i--;
        }
        pq.a[i + 1] = ele;
        pq.size++;
        cout << "Element Inserted" << endl;
    }

    int remove() {
        if (pq.size == 0) {
            cout << "Priority Queue is empty" << endl;
            return -1;
        }
        int ele = pq.a[0];
        for (int i = 1; i < pq.size; i++) {
            pq.a[i - 1] = pq.a[i];
        }
        pq.size--;
        return ele;
    }

    void display() {
        if (pq.size == 0) {
            cout << "Priority Queue is empty" << endl;
            return;
        }
        for (int i = 0; i < pq.size; i++) {
            cout << pq.a[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Operation opp;
    int choice, ele;
    cout << "\n1. Insert\n2. Remove\n3. Display\n4. Exit\nEnter choice: ";
    do {
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> ele;
                opp.insert(ele);
                break;
            case 2:
                ele = opp.remove();
                if (ele != -1)
                    cout << "Removed element: " << ele << endl;
                break;
            case 3:
                opp.display();
                break;
            case 4:
                cout << "Exiting\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);
    return 0;
}