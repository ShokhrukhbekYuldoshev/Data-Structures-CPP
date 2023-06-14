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

class BinaryTree
{
private:
    Node *root;

public:
    BinaryTree()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        if (root == nullptr)
        {
            root = new Node(value);
            return;
        }

        Node *current = root;
        while (true)
        {
            if (value < current->data)
            {
                if (current->left == nullptr)
                {
                    current->left = new Node(value);
                    break;
                }
                else
                {
                    current = current->left;
                }
            }
            else
            {
                if (current->right == nullptr)
                {
                    current->right = new Node(value);
                    break;
                }
                else
                {
                    current = current->right;
                }
            }
        }
    }

    bool search(int value)
    {
        return searchRecursive(root, value);
    }

private:
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
    BinaryTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    std::cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 90: " << (tree.search(90) ? "Found" : "Not Found") << std::endl;

    return 0;
}
