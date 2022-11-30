/* Binary Search Tree implementation in C++ */

#include <iostream>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};

// Create a node
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Inorder Traversal
void inorder(struct node *root)
{
    if (root != NULL)
    {
        // Traverse left
        inorder(root->left);

        // Traverse root
        cout << root->key << " -> ";

        // Traverse right
        inorder(root->right);
    }
}

// Insert a node
struct node *insert(struct node *node, int key)
{
    // Return a new node if the tree is empty
    if (node == NULL)
        return newNode(key);

    // Traverse to the right place and insert the node
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    // Find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key)
{
    // Return if the tree is empty
    if (root == NULL)
        return root;

    // Find the node to be deleted
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        // If the node is with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // If the node has two children
        struct node *temp = minValueNode(root->right);

        // Place the inorder successor in position of the node to be deleted
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Driver code
int main()
{
    struct node *root = NULL;

    /* implement menu driven */
    int choice, key;
    char ch = 'y';
    while (ch == 'y')
    {
        cout << "1. Insertion" << endl
             << "2. Deletion" << endl
             << "3. Inorder Traversal" << endl
             << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
    loop:
        switch (choice)
        {
        case 1:
            cout << "Enter the key to be inserted: ";
            cin >> key;
            root = insert(root, key);
            break;

        case 2:
            cout << "Enter the key to be deleted: ";
            cin >> key;
            root = deleteNode(root, key);
            break;

        case 3:
            inorder(root);
            cout << endl;
            break;

        case 4:
            exit(1);

        default:
            cout << "Wrong choice" << endl;
            goto loop;
        }
        cout << endl;
        cout << "Do you want to continue? (y/n): ";
        cin >> ch;
        cout << endl;
    }
    return 0;
}
