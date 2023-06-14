#include <iostream>
#include <algorithm>

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree
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

    Node *rotateLeft(Node *node)
    {
        Node *newRoot = node->right;
        Node *subtree = newRoot->left;

        newRoot->left = node;
        node->right = subtree;

        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        newRoot->height = 1 + std::max(getHeight(newRoot->left), getHeight(newRoot->right));

        return newRoot;
    }

    Node *rotateRight(Node *node)
    {
        Node *newRoot = node->left;
        Node *subtree = newRoot->right;

        newRoot->right = node;
        node->left = subtree;

        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        newRoot->height = 1 + std::max(getHeight(newRoot->left), getHeight(newRoot->right));

        return newRoot;
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
            // Duplicate values not allowed
            return node;
        }

        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

        int balanceFactor = getBalanceFactor(node);

        // Left Left Case
        if (balanceFactor > 1 && value < node->left->data)
        {
            return rotateRight(node);
        }

        // Right Right Case
        if (balanceFactor < -1 && value > node->right->data)
        {
            return rotateLeft(node);
        }

        // Left Right Case
        if (balanceFactor > 1 && value > node->left->data)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left Case
        if (balanceFactor < -1 && value < node->right->data)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void printInorder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        printInorder(node->left);
        std::cout << node->data << " ";
        printInorder(node->right);
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int value)
    {
        root = insertNode(root, value);
    }

    void printInorderTraversal()
    {
        printInorder(root);
        std::cout << std::endl;
    }
};

int main()
{
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(60);
    tree.insert(70);
    tree.insert(80);
    tree.insert(90);

    tree.printInorderTraversal();

    return 0;
}
