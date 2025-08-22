                                                                         #include <iostream>
using namespace std;

struct queue
{
    int a[5];
    int front;
    int rear;
    int n;
    queue() : front(-1), rear(-1), n(5) {}
} q;

class operation
{
public:
    void insert(int ele)
    {
        if (q.rear == -1)
        {
            q.rear++;
            q.front++;
            q.a[q.rear] = ele;
            cout << "Element Inserted" << endl;
        }
        else if (!isfull())
        {
            q.rear++;
            q.a[q.rear] = ele;
            cout << "Element Inserted" << endl;
        }
        else
        {
            cout << "Queue is full" << endl;
        }
    }

    int remove()
    {
        if (!isempty())
        {
            int ele = q.a[q.front];
            q.a[q.front] = 0;
            if (q.front == q.rear)
            {
                q.front = q.rear = -1;
            }
            else
            {
                q.front++;
            }
            return ele;
        }
        else
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
    }

    void display()
    {
        if (!isempty())
        {
            int i = q.front;
            while (true)
            {
                cout << q.a[i] << " ";
                if (i == q.rear)
                    break;
                i++;
            }
            cout << endl;
        }
        else
        {
            cout << "Queue is empty" << endl;
        }
    }

    bool isfull()
    {
        return (q.rear  == q.front);
    }

    bool isempty()
    {
        return (q.front == -1);
    }
};

int main()
{
    operation opp;
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