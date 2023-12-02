#include <iostream>
#define MAX 10
using namespace std;

struct queue
{
    int data[MAX];
    int front, rear;
};

class Queue
{
    struct queue q;

public:
    Queue() { q.front = q.rear = -1; }
    int isempty();
    int isfull();
    void enqueue(int);
    int delqueue();
    void display();
};

int Queue::isempty()
{
    return (q.front == q.rear) ? 1 : 0;
}

int Queue::isfull()
{
    return (q.rear == MAX - 1) ? 1 : 0;
}

void Queue::enqueue(int x)
{
    if (!isfull())
    {
        q.data[++q.rear] = x;
        cout << "Enqueued: " << x << endl;
    }
    else
    {
        cout << "Queue is overflow!!!\n\n";
    }
}

int Queue::delqueue()
{
    if (!isempty())
    {
        return q.data[++q.front];
    }
    else
    {
        cout << "Queue is underflow!!!\n\n";
        // You may want to return a special value or throw an exception here
        // to indicate that the queue is empty.
        return -1; // Placeholder for an empty queue
    }
}

void Queue::display()
{
    if (!isempty())
    {
        cout << "\nQueue contains: ";
        for (int i = q.front + 1; i <= q.rear; i++)
            cout << q.data[i] << " ";
        cout << endl;
    }
    else
    {
        cout << "\nQueue is empty!!!\n\n";
    }
}

int main()
{
    Queue obj;
    int ch, x;
    do
    {
        cout << "\n 1. Insert Job\n 2. Delete Job\n 3. Display\n 4. Exit\n Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            if (!obj.isfull())
            {
                cout << "\nEnter data: ";
                cin >> x;
                obj.enqueue(x);
            }
            else
            {
                cout << "Queue is overflow!!!\n\n";
            }
            break;
        case 2:
            if (!obj.isempty())
            {
                cout << "\nDeleted Element = " << obj.delqueue() << endl;
                cout << "Remaining Jobs: ";
                obj.display();
            }
            else
            {
                cout << "\nQueue is underflow!!!\n\n";
            }
            break;
        case 3:
            obj.display();
            break;
        case 4:
            cout << "\nExiting Program.....\n";
            break;
        default:
            cout << "\nInvalid Choice! Please enter a valid option.\n";
        }
    } while (ch != 4);

    return 0;
}
