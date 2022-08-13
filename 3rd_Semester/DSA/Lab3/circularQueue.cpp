// Circular Queue implementation in C++
#include <iostream>

using namespace std;

class Queue
{
private:
    int size, *items, front, rear;

public:
    Queue(int size = 10)
    {
        this->size = size;
        items = new int[size];
        front = -1;
        rear = -1;
    }

    // Check if the queue is full
    bool isFull()
    {
        if (front == 0 && rear == size - 1 || front == rear + 1)
        {
            return true;
        }
        return false;
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }

    // Adding an element
    void enQueue(int element)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear = (rear + 1) % size;
            items[rear] = element;
            cout << endl
                 << "Inserted " << element
                 << endl;
        }
    }
    
    // Removing an element
    int deQueue()
    {
        int element;
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return (-1);
        }
        else
        {
            element = items[front];
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            // Q has only one element,
            // so we reset the queue after deleting it.
            else
            {
                front = (front + 1) % size;
            }
            return (element);
        }
    }

    void display()
    {
        // Function to display status of Circular Queue
        int i;
        if (isEmpty())
        {
            cout << endl
                 << "Empty Queue" << endl;
        }
        else
        {
            cout << "Front -> " << front;
            cout << endl
                 << "Items -> ";
            for (i = front; i != rear; i = (i + 1) % size)
                cout << items[i];
            cout << items[i];
            cout << endl
                 << "Rear -> " << rear;
        }
    }
};

int main()
{
    Queue q;

    // Fails because front = -1
    q.deQueue();

    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    // Fails to enqueue because front == 0 && rear == size - 1
    q.enQueue(6);

    q.display();

    int elem = q.deQueue();

    if (elem != -1)
        cout << endl
             << "Deleted Element is " << elem;

    q.display();

    q.enQueue(7);

    q.display();

    // Fails to enqueue because front == rear + 1
    q.enQueue(8);

    return 0;
}
