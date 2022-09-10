#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    struct node *prev;
    struct node *next;
    int data;
};

struct node *head;

/*functions*/
void insertion_beginning();
void insertion_last();
void deletion_beginning();
void deletion_last();
void display();
void search();

int main()
{
    int choice = 0;
    do
    {
        system("cls");
        cout << "Choose one option from the following list" << endl;
        cout << "===============================================" << endl;
        cout << "1.Insert in begining" << endl
             << "2.Insert at last" << endl
             << "3.Delete from Beginning" << endl
             << "4.Delete from last" << endl
             << "5.Search for an element" << endl
             << "6.Show" << endl
             << "7.Exit" << endl;
        cout << "===============================================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insertion_beginning();
            break;

        case 2:
            insertion_last();
            break;

        case 3:
            deletion_beginning();
            break;

        case 4:
            deletion_last();
            break;

        case 5:
            search();
            break;

        case 6:
            display();
            break;

        case 7:
            exit(0);
            break;

        default:
            cout << "Please enter valid choice\b" << endl;
        }
    } while (choice != 9);

    return 0;
}

void insertion_beginning()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        cout << "OVERFLOW" << endl;
    }
    else
    {
        cout << "Enter value: ";
        cin >> item;

        ptr->data = item;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
            ptr->prev = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            head->prev = ptr;
            ptr->next = head;
            head = ptr;
        }
        cout << "Node inserted" << endl;
    }
}

void insertion_last()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        cout << "OVERFLOW" << endl;
    }
    else
    {
        cout << "Enter value: ";
        cin >> item;

        ptr->data = item;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
            ptr->prev = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            head->prev = ptr;
            ptr->next = head;
        }
    }
    cout << "Node inserted" << endl;
}

void deletion_beginning()
{
    struct node *temp;
    if (head == NULL)
    {
        cout << " UNDERFLOW" << endl;
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        cout << "Node deleted" << endl;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        head->next->prev = temp;
        free(head);
        head = temp->next;
    }
}

void deletion_last()
{
    struct node *ptr;
    if (head == NULL)
    {
        cout << " UNDERFLOW" << endl;
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        cout << "Node deleted" << endl;
    }
    else
    {
        ptr = head;
        if (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = head;
        head->prev = ptr->prev;
        free(ptr);
        cout << "Node deleted" << endl;
    }
}

void display()
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        cout << "Nothing to print" << endl;
    }
    else
    {
        cout << "Printing values:" << endl;

        while (ptr->next != head)
        {

            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << ptr->data;
    }
    cout << endl;
}

void search()
{
    struct node *ptr;
    int item, i = 0, flag = 1;
    ptr = head;
    if (ptr == NULL)
    {
        cout << "Empty List" << endl;
    }
    else
    {
        cout << "Enter item which you want to search: ";
        cin >> item;

        if (head->data == item)
        {
            cout << "Item found at location " << i + 1 << endl;
            flag = 0;
        }
        else
        {
            while (ptr->next != head)
            {
                if (ptr->data == item)
                {
                    cout << "Item found at location " << i + 1 << endl;
                    flag = 0;
                    break;
                }
                else
                {
                    flag = 1;
                }
                i++;
                ptr = ptr->next;
            }
        }
        if (flag != 0)
        {
            cout << "Item not found" << endl;
        }
    }
}
