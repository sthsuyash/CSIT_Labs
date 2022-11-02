#include <iostream>
#include <array>
using namespace std;

class Stack
{
private:
    array<int, 20> arr;

public:
    int top;
    int size = arr.size();

    Stack() { top = -1; }

    void makeEmpty()
    {
        top = -1;
        cout << "Stack Emptied." << endl;
    }

    bool isOverFlow()
    {
        if (top > size - 1)
        {
            return 1;
        }
        return 0;
    }

    bool isUnderFlow()
    {
        if (top < 0)
        {
            return 1;
        }
        return 0;
    }

    bool isEmpty()
    {
        if (isUnderFlow())
        {
            return 1;
        }
        return 0;
    }

    int get_top()
    {
        return this->arr[top];
    }

    void push(int data)
    {
        if (!isOverFlow())
        {
            top++;
            this->arr[top] = data;
            cout << data << " pushed successfully!!" << endl;
        }
        else
        {
            cout << "Stack Overflow. Cannot push data\b" << endl;
        }
    }

    void pop()
    {
        if (!isUnderFlow())
        {
            int data = this->arr[top];
            top--;
            cout << data << " popped successfully!!" << endl;
        }
        else
        {
            cout << "Pop operation unsuccessful!!" << endl;
        }
    }

    void peakOp(int data)
    {
        if (!isEmpty())
        {
            this->arr[top] = data;
            cout << "Peak operation successful." << endl;
        }
        else
        {
            cout << "Peak operation unsuccessful!!" << endl;
        }
    }

    void stackTraversal()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty";
            return;
        }

        cout << "Stack traversal from top to bottom:" << endl;
        int top_store = top;
        while (!isUnderFlow())
        {
            cout << arr[top] << " ";
            top--;
        }
        top = top_store;
    }

    void displayEmpty()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "Stack is not empty." << endl
                 << "Top pointer: " << top << endl;
        }
    }
};

int main()
{
    Stack stack;

    cout << "Press the following for specific operations:" << endl;
    cout << "1) Empty Stack." << endl;
    cout << "2) Push operation." << endl;
    cout << "3) Pop operation." << endl;
    cout << "4) Peak operation." << endl;
    cout << "5) Display item in stack." << endl;

    int choice, data;
    char ch;

    do
    {
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            stack.makeEmpty();
            cout << endl;
            break;

        case 2:
            cout << "Enter data to push: ";
            cin >> data;
            stack.push(data);
            cout << endl;
            break;

        case 3:
            stack.pop();
            cout << endl;
            break;

        case 4:
            cout << "Enter data for peak: ";
            cin >> data;
            stack.peakOp(data);
            break;

        case 5:
            stack.stackTraversal();
            cout << endl;
            break;

        default:
            cout << "Please press valid option." << endl;
            break;
        }
        cout << "Do you want to continue again(y/n)? ";
        cin >> ch;

    } while (ch == 'y');

    return 0;
}
