#include <iostream>

struct Node
{
    int data;
    int height;
    Node *left;
    Node *right;

    Node(int value) : data(value), height(1), left(nullptr), right(nullptr) {}
};

class AVLSet
{
private:
    Node *root;

    int getHeight(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return node->height;
    }

    int getBalanceFactor(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    Node *insertNode(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = insertNode(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertNode(node->right, value);
        }
        else
        {
            // Duplicate values are not allowed in the set
            return node;
        }

        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

        int balanceFactor = getBalanceFactor(node);

        // Left Left Case
        if (balanceFactor > 1 && value < node->left->data)
        {
            return rightRotate(node);
        }

        // Right Right Case
        if (balanceFactor < -1 && value > node->right->data)
        {
            return leftRotate(node);
        }

        // Left Right Case
        if (balanceFactor > 1 && value > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balanceFactor < -1 && value < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inOrderTraversal(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inOrderTraversal(node->left);
        std::cout << node->data << " ";
        inOrderTraversal(node->right);
    }

public:
    AVLSet() : root(nullptr) {}

    void insert(int value)
    {
        root = insertNode(root, value);
    }

    void printSet()
    {
        inOrderTraversal(root);
        std::cout << std::endl;
    }
};

int main()
{
    AVLSet mySet;

    mySet.insert(10);
    mySet.insert(5);
    mySet.insert(20);
    mySet.insert(15);
    mySet.insert(30);
    mySet.insert(25);
    mySet.insert(35);
    mySet.insert(35);
    mySet.insert(35);

    mySet.printSet();

    return 0;
}
