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
    
    void makeEmpty(){
    	if(isEmpty()){
    		cout<<"Queue already empty."<<endl; 
		}
		else{
			front = -1;
        	rear = -1;
		}
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
        	cout << "Queue Traversal:\n";
      		for(i = front; i != rear; i = (i + 1) % size)
			{
        		cout << items[i]<<" ";
    		}
      		cout << items[i]<< " ";
        }
    }
    
};

int main()
{
    Queue q(2);

	int choice, item;
	char ch;
	
	do{
		cout<<"Press:"<<endl<<
		"1. to make empty."<<endl<<
		"2. for enqueue"<<endl<<
		"3. for dequeue"<<endl<<
		"4. for traversal"<<endl;
		
		cin >> choice;
		
		switch(choice){
			case 1:
				q.makeEmpty();
				cout<<"Queue Emptied."<<endl;
				break;
				
			case 2:
				cout<<"Enter item: ";
				cin>>item;
				q.enQueue(item);
				break;
				
			case 3:
				cout<< q.deQueue() << " deleted."<<endl;
				break;
				
			case 4:
				q.display();
				cout<<endl;
				break;
				
			default:
				break;
		}
		
		cout<<"Do you want to continue again?(y/n): ";
		cin>>ch;
	}while(ch=='y');
	
	cout<<"End of program."<<endl;

    return 0;
}
