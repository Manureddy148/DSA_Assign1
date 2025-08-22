#include <iostream>
using namespace std;
struct stack
{
    int arr[5];
    int top;
    stack() : top(-1) {} 
}st;
class operations {
    int n = 5,i,ele;
    public:
    void push(int ele) {
        if (st.top != n - 1) {
            st.top++;
            st.arr[st.top] = ele;
        } else {
            cout << "Stack Overflow\n";
        }
    }

    int pop() {
        if (st.top >= 0) {
            int ele = st.arr[st.top];
            st.top--;
            return ele;
        } else {
            cout << "Stack Underflow\n";
            return -1; 
        }
    }

    void display() {
        cout << "Elements in stack:\n";
        for (int i = 0; i <= st.top; i++) {
            cout << st.arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    operations st1;
    printf("Stack Operations\n");
    cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";
    int choice;
    int ele; 
    do {
        cin >> choice;
        switch (choice) {
            case 1: // Push operation
                cout << "Enter element to push: ";
                cin >> ele;
                st1.push(ele);
                break;
            case 2: // Pop operation
                cout << "Popped element: " << st1.pop() << endl;
                break;
            case 3: // Display stack
                st1.display();
                break;
            case 4: // Exit
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
    return 0;
}
