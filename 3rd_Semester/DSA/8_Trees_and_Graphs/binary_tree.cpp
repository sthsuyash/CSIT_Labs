// Binary Tree in C++
#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// New node creation
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));

    node->data = data;

    node->left = NULL;
    node->right = NULL;
    return (node);
}

void traversePreOrder(struct node *temp);
void traverseInOrder(struct node *temp);
void traversePostOrder(struct node *temp);

int main()
{
    struct node *root = NULL;

    // menu driven
    int choice, data;
    char ch = 'y';

    while (ch == 'y' || ch == 'Y')
    {
    loop:
        cout << "1. Insert" << endl
             << "2. Preorder Traversal" << endl
             << "3. Inorder Traversal" << endl
             << "4. Postorder Traversal" << endl
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the data: ";
            cin >> data;
            if (root == NULL)
            {
                root = newNode(data);
            }
            else
            {
                struct node *temp = root;
                struct node *parent = NULL;
                while (temp != NULL)
                {
                    parent = temp;
                    if (data < temp->data)
                    {
                        temp = temp->left;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
                if (data < parent->data)
                {
                    parent->left = newNode(data);
                }
                else
                {
                    parent->right = newNode(data);
                }
            }
            break;
        case 2:
            cout << "\nPreorder Traversal: ";
            traversePreOrder(root);
            cout << endl;
            break;
        case 3:
            cout << "\n\nInorder Traversal: ";
            traverseInOrder(root);
            cout << endl;
            break;
        case 4:
            cout << "\n\nPostorder Traversal: ";
            traversePostOrder(root);
            cout << endl;
            break;
        default:
            cout << "\n\nInvalid choice" << endl;
            goto loop;
        }
        cout << "\nDo you want to continue? (y/n): ";
        cin >> ch;
    }
    return 0;
}

// Traverse Preorder
void traversePreOrder(struct node *temp)
{
    if (temp != NULL)
    {
        cout << temp->data << "->";
        traversePreOrder(temp->left);
        traversePreOrder(temp->right);
    }
}

// Traverse Inorder
void traverseInOrder(struct node *temp)
{
    if (temp != NULL)
    {
        traverseInOrder(temp->left);
        cout << temp->data << "->";
        traverseInOrder(temp->right);
    }
}

// Traverse Postorder
void traversePostOrder(struct node *temp)
{
    if (temp != NULL)
    {
        traversePostOrder(temp->left);
        traversePostOrder(temp->right);
        cout << temp->data << "->";
    }
}
