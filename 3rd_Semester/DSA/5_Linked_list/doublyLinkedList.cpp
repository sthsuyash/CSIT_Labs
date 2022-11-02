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

/* functions */
void insertion_beginning();
void insertion_last();
void insertion_specified();
void deletion_beginning();
void deletion_last();
void deletion_specified();
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
             << "3.Insert at any random location" << endl
             << "4.Delete from Beginning" << endl
             << "5.Delete from last" << endl
             << "6.Delete the node after the given data" << endl
             << "7.Search for an element" << endl
             << "8.Show" << endl
             << "9.Exit" << endl;
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
            insertion_specified();
            break;

        case 4:
            deletion_beginning();
            break;

        case 5:
            deletion_last();
            break;

        case 6:
            deletion_specified();
            break;

        case 7:
            search();
            break;

        case 8:
            display();
            break;

        case 9:
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
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        cout << "OVERFLOW" << endl;
    }
    else
    {
        cout << "Enter value:";
        cin >> item;

        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            ptr->data = item;
            head = ptr;
        }
        else
        {
            ptr->data = item;
            ptr->prev = NULL;
            ptr->next = head;
            head->prev = ptr;
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
        cout << "Enter value:";
        cin >> item;

        ptr->data = item;
        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
        }
    }
    cout << "Node inserted" << endl;
}

void insertion_specified()
{
    struct node *ptr, *temp;
    int item, loc, i;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        cout << "OVERFLOW" << endl;
    }
    else
    {
        temp = head;
        cout << "Enter the location: ";
        cin >> loc;
        for (i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                cout << "There are less than " << loc << " elements." << endl;
                return;
            }
        }

        cout << "Enter value: ";
        cin >> item;

        ptr->data = item;
        ptr->next = temp->next;
        ptr->prev = temp;
        temp->next = ptr;

        temp->next->prev = ptr;
        cout << "Node inserted" << endl;
    }
}

void deletion_beginning()
{
    struct node *ptr;
    if (head == NULL)
    {
        cout << "UNDERFLOW" << endl;
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        cout << "Node deleted" << endl;
    }
    else
    {
        ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
        cout << "Node deleted\n";
    }
}

void deletion_last()
{
    struct node *ptr;
    if (head == NULL)
    {
        cout << "UNDERFLOW" << endl;
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        cout << "Node deleted" << endl;
    }
    else
    {
        ptr = head;
        if (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
        cout << "Node deleted" << endl;
    }
}

void deletion_specified()
{
    struct node *ptr, *temp;
    int val;

    cout << "Enter the data after which the node is to be deleted : ";
    cin >> val;
    ptr = head;

    while (ptr->data != val)
    {
        ptr = ptr->next;
    }

    if (ptr->next == NULL)
    {
        cout << "Can't delete" << endl;
    }
    else if (ptr->next->next == NULL)
    {
        ptr->next = NULL;
    }
    else
    {
        temp = ptr->next;
        ptr->next = temp->next;
        temp->next->prev = ptr;
        free(temp);
        cout << "Node deleted" << endl;
    }
}

void display()
{
    struct node *ptr;
    cout << "Printing values:" << endl;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void search()
{
    struct node *ptr;
    int item, i = 0, flag;
    ptr = head;
    if (ptr == NULL)
    {
        cout << "Empty List" << endl;
    }
    else
    {
        cout << "Enter item which you want to search: ";
        cin >> item;

        while (ptr != NULL)
        {
            if (ptr->data == item)
            {
                cout << "Item found at location " << i + 1;
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
        if (flag == 1)
        {
            cout << "Item not found" << endl;
        }
    }
}
