#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree
{
private:
    Node *root;

public:
    BinarySearchTree()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        root = insertRecursive(root, value);
    }

    bool search(int value)
    {
        return searchRecursive(root, value);
    }

private:
    Node *insertRecursive(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = insertRecursive(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

    bool searchRecursive(Node *node, int value)
    {
        if (node == nullptr)
        {
            return false;
        }
        else if (node->data == value)
        {
            return true;
        }
        else if (value < node->data)
        {
            return searchRecursive(node->left, value);
        }
        else
        {
            return searchRecursive(node->right, value);
        }
    }
};

int main()
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Search 40: " << (bst.search(40) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 90: " << (bst.search(90) ? "Found" : "Not Found") << std::endl;

    return 0;
}
