#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};

// return greater from two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Tree Height Calculator
int getHeight(Node *n)
{
    return (n == NULL) ? 0 : n->height;
}

// Balance Factor Calculator
int getBalance(Node *node)
{
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Right Rotation
Node *rotateRight(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform Rotation
    x->right = y;
    y->left = T2;

    // Update Heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Left Rotation
Node *rotateLeft(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update Height
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Creating a New Node
Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// Inserting in a tree
Node *insertNode(Node *node, int data)
{
    // 1. Normal BST Insertion
    if (node == NULL)
        return (newNode(data));

    if (data < node->data)
    {
        node->left = insertNode(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insertNode(node->right, data);
    }
    else
        return node; // Duplicate Key Restriction

    // 2. Update Height of a Parent Node/current Node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // 3. Get Balance Factor
    int balance = getBalance(node); // 2

    // ---------4. Balancing the tree-----------

    // I. Left Left Case
    // 40 < 35
    if (balance > 1 && data < node->left->data)
        return rotateRight(node);

    // II. Right Right Case
    if (balance < -1 && data > node->right->data)
        return rotateLeft(node);

    // III. Left Right Case
    if (balance > 1 && data > node->left->data)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // IV. Right Left Case
    if (balance < -1 && data < node->right->data)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void printTree(Node *root, string indent, bool last)
{
    if (root != nullptr)
    {
        cout << indent;
        if (last)
        {
            cout << "R----";
            indent += "   ";
        }
        else
        {
            cout << "L----";
            indent += "|  ";
        }
        cout << root->data << endl;
        printTree(root->left, indent, false);
        printTree(root->right, indent, true);
    }
}

int main()
{
    Node *root = NULL;
    root = insertNode(root, 40);
    root = insertNode(root, 30);
    root = insertNode(root, 60);
    root = insertNode(root, 50);
    root = insertNode(root, 55);
    // root = insertNode(root, 33);
    // root = insertNode(root, 33);

    // cout << "\nInorder traversal of AVL Tree: \n";
    // inOrder(root);
    // cout << endl;

    printTree(root, "", true);

    return 0;
}