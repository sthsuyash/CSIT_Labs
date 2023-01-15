#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *root = NULL;

Node *insert(Node *node, int data)
{
    if (node == NULL)
    {
        node = new Node();
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }
    else if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else
    {
        node->right = insert(node->right, data);
    }
    return node;
}

bool search(Node *node, int data)
{
    if (node == NULL)
    {
        return false;
    }
    else if (node->data == data)
    {
        return true;
    }
    else if (data <= node->data)
    {
        return search(node->left, data);
    }
    else
    {
        return search(node->right, data);
    }
}

void inOrderTraversal(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    inOrderTraversal(node->left);
    cout << node->data << " ";
    inOrderTraversal(node->right);
}

void preOrderTraversal(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->data << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

void postOrderTraversal(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout << node->data << " ";
}

int main()
{
    int choice, data;
    do
    {
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. In-Order Traversal" << endl;
        cout << "4. Pre-Order Traversal" << endl;
        cout << "5. Post-Order Traversal" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            root = insert(root, data);
            break;
        case 2:
            cout << "Enter data: ";
            cin >> data;
            if (search(root, data))
            {
                cout << data << " is found in the tree." << endl;
            }
            else
            {
                cout << data << " is not found in the tree." << endl;
            }
            break;
        case 3:
            cout << "In-Order Traversal: ";
            inOrderTraversal(root);
            cout << endl;
            break;
        case 4:
            cout << "Pre-Order Traversal: ";
            preOrderTraversal(root);
            cout << endl;
            break;
        case 5:
            cout << "Post-Order Traversal: ";
            postOrderTraversal(root);
            cout << endl;
            break;
        case 6:
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);
    return 0;
}
