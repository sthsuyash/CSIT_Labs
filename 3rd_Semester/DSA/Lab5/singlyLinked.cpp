/**
	WAP to perform the following task using singly linked list
	1) insert at beginning
	2) insert at specific position
	3) insert at end of list
	4) delete from beginning
	5) delete from specific position
	6) delete from end
	7) traverse the list
**/

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
};

class LinkedList{
    private:
        node *head;

    public:
        LinkedList(){
            head = NULL;
        }

        void insertAtEnd(int data){
            node *temp = new node;
            temp->data = data;
            temp->next = NULL;

            if(head == NULL){
                head = temp;
            }
            else{
                node *temp1 = head;
                while(temp1->next != NULL){
                    temp1 = temp1->next;
                }
                temp1->next = temp;
            }
        }

        void insertAtBeginning(int data){
            node *temp = new node;
            temp->data = data;
            temp->next = head;
            head = temp;
        }

        void insertAtPosition(int data){
            int pos;
            cout << "Enter position: ";
            cin >> pos;

            node *temp = new node;
            temp->data = data;
            temp->next = NULL;

            if(pos == 1){
                temp->next = head;
                head = temp;
            }
            else{
                node *temp1 = head;
                for(int i = 0; i < pos - 2; i++){
                    temp1 = temp1->next;
                }
                temp->next = temp1->next;
                temp1->next = temp;
            }
        }

        void deleteAtBeginning(){
            node *temp = head;
            head = head->next;
            delete temp;
        }

        void deleteAtEnd(){
            node *temp = head;
            while(temp->next->next != NULL){
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }

        void deleteAtposition(){
            int pos;
            cout << "Enter position: ";
            cin >> pos;

            if(pos == 1){
                node *temp = head;
                head = head->next;
                delete temp;
            }
            else{
                node *temp = head;
                for(int i = 0; i < pos - 2; i++){
                    temp = temp->next;
                }
                node *temp1 = temp->next;
                temp->next = temp1->next;
                delete temp1;
            }
        }

        void displayList(){
            node *temp = head;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main(){
    int choice;
    char ch;
    // menu driven program
    cout<<"1)Insert at beginning"<<endl;
    cout<<"2)Insert at end"<<endl;
    cout<<"3)Insert at position"<<endl;
    cout<<"4)Delete at beginning"<<endl;
    cout<<"5)Delete at end"<<endl;
    cout<<"6)Delete at position"<<endl;
    cout<<"7)Display list"<<endl;
    cout<<"8)Exit"<<endl;

    LinkedList list;
    
    do{
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                int data;
                cout<<"Enter data: ";
                cin>>data;
                list.insertAtBeginning(data);
                break;

            case 2:
                int data1;
                cout<<"Enter data: ";
                cin>>data1;
                list.insertAtEnd(data1);
                break;

            case 3:
                int data2;
                cout<<"Enter data: ";
                cin>>data2;
                list.insertAtPosition(data2);
                break;

            case 4:
                list.deleteAtBeginning();
                break;

            case 5:
                list.deleteAtEnd(); 
                break;

            case 6:
                list.deleteAtposition();
                break;

            case 7:
                list.displayList();
                break;

            default:
                cout<<"Enter valid number"<<endl;
        }
        cout << "Do you want to continue?(y/n): ";
        cin >> ch;
    }while(ch == 'y' || ch == 'Y');
    
    return 0;
}
