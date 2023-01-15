// linear queue

#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue()
{
    if (rear == MAX_SIZE - 1)
    {
        cout << "Queue is full!" << endl;
        return;
    }
    int value;
    cout << "Enter a value to enqueue: ";
    cin >> value;
    if (front == -1)
        front = 0;
    queue[++rear] = value;
    cout << value << " has been enqueued." << endl;
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << queue[front] << " has been dequeued." << endl;
    front++;
}

void display()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Queue: ";
    for (int i = front; i <= rear; i++)
    {
        cout << queue[i] << " ";
    }
    cout << endl;
}

void make_empty()
{
    front = -1;
    rear = -1;
    cout << "Queue is now empty" << endl;
}

int main()
{
    int choice;
    do
    {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Make Empty" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            make_empty();
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);
    return 0;
}

// circular queue

// #include <iostream>
// using namespace std;

// const int MAX_SIZE = 100;

// int queue[MAX_SIZE];
// int front = -1, rear = -1;

// void enqueue()
// {
//     if ((rear + 1) % MAX_SIZE == front)
//     {
//         cout << "Queue is full!" << endl;
//         return;
//     }
//     int value;
//     cout << "Enter a value to enqueue: ";
//     cin >> value;
//     if (front == -1)
//         front = 0;
//     rear = (rear + 1) % MAX_SIZE;
//     queue[rear] = value;
//     cout << value << " has been enqueued." << endl;
// }

// void dequeue()
// {
//     if (front == -1)
//     {
//         cout << "Queue is empty!" << endl;
//         return;
//     }
//     cout << queue[front] << " has been dequeued." << endl;
//     front = (front + 1) % MAX_SIZE;
//     if (front == rear)
//     {
//         front = -1;
//         rear = -1;
//     }
// }

// void display()
// {
//     if (front == -1)
//     {
//         cout << "Queue is empty!" << endl;
//         return;
//     }
//     cout << "Queue: ";
//     for (int i = front; i != rear; i = (i + 1) % MAX_SIZE)
//     {
//         cout << queue[i] << " ";
//     }
//     cout << queue[rear] << endl;
// }

// void make_empty()
// {
//     front = -1;
//     rear = -1;
//     cout << "Queue is now empty" << endl;
// }

// int main()
// {
//     int choice;
//     do
//     {
//         cout << "1. Enqueue" << endl;
//         cout << "2. Dequeue" << endl;
//         cout << "3. Display" << endl;
//         cout << "4. Make Empty" << endl;
//         cout << "5. Exit" << endl;
//         cout << "Enter your choice: ";
//         cin >> choice;
//         switch (choice)
//         {
//         case 1:
//             enqueue();
//             break;
//         case 2:
//             dequeue();
//             break;
//         case 3:
//             display();
//             break;
//         case 4:
//             make_empty();
//             break;
//         case 5:
//             break;
//         default:
//             cout << "Invalid choice!" << endl;
//         }
//     } while (choice != 5);
//     return 0;
// }
