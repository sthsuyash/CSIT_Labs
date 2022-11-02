#include <iostream>
#include <cstdlib>
using namespace std;

// A class to store a queue
class Queue
{
    int *arr;     // array to store queue elements
    int capacity; // maximum capacity of the queue
    int front;    // front points to the front element in the queue (if any)
    int rear;     // rear points to the last element in the queue
    int count;    // current size of the queue

public:
    // Constructor to initialize a queue
    Queue(int size = 10)
    {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    // Utility function to dequeue the front element
    int dequeue()
    {
        // check for queue underflow
        if (isEmpty())
        {
            cout << "Underflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }

        int x = arr[front];
        cout << "Removing " << x << endl;

        front = front++;
        count--;

        return x;
    }

    // Utility function to add an item to the queue
    void enqueue(int item)
    {
        // check for queue overflow
        if (isFull())
        {
            cout << "Overflow" << endl
                 << "Program Terminated"<<endl;
            exit(EXIT_FAILURE);
        }

        cout << "Inserting " << item << endl;

        rear++;
        arr[rear] = item;
        count++;
    }

    // Utility function to return the size of the queue
    int size()
    {
        return count;
    }

    // Utility function to check if the queue is empty or not
    bool isEmpty()
    {
        return (size() == 0);
    }

    // Utility function to check if the queue is full or not
    bool isFull()
    {
        return (size() == capacity);
    }

    void makeEmpty()
    {
        front = 0;
        rear = -1;
        count = 0;
    }

    void display()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;

    int choice, item;
    char ch;

    do
    {
        cout << "Press:" << endl
             << "1. to make empty." << endl
             << "2. for enqueue" << endl
             << "3. for dequeue" << endl
             << "4. for traversal" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            q.makeEmpty();
            cout << "Queue Emptied." << endl;
            break;

        case 2:
            cout << "Enter item: ";
            cin >> item;
            q.enqueue(item);
            break;

        case 3:
            cout << q.dequeue() << " deleted." << endl;
            break;

        case 4:
            q.display();
            cout << endl;
            break;

        default:
            break;
        }

        cout << "Do you want to continue again?(y/n): ";
        cin >> ch;
    } while (ch == 'y');

    cout << "End of program." << endl;

    return 0;
}
