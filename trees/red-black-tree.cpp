#include <iostream>

enum class Color
{
    RED,
    BLACK
};

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;
    Color color;

    explicit Node(int value) : data(value), left(nullptr), right(nullptr), parent(nullptr), color(Color::RED) {}
};

class RedBlackTree
{
private:
    Node *root;

    void leftRotate(Node *node)
    {
        Node *rightChild = node->right;
        node->right = rightChild->left;

        if (rightChild->left != nullptr)
        {
            rightChild->left->parent = node;
        }

        rightChild->parent = node->parent;

        if (node->parent == nullptr)
        {
            root = rightChild;
        }
        else if (node == node->parent->left)
        {
            node->parent->left = rightChild;
        }
        else
        {
            node->parent->right = rightChild;
        }

        rightChild->left = node;
        node->parent = rightChild;
    }

    void rightRotate(Node *node)
    {
        Node *leftChild = node->left;
        node->left = leftChild->right;

        if (leftChild->right != nullptr)
        {
            leftChild->right->parent = node;
        }

        leftChild->parent = node->parent;

        if (node->parent == nullptr)
        {
            root = leftChild;
        }
        else if (node == node->parent->left)
        {
            node->parent->left = leftChild;
        }
        else
        {
            node->parent->right = leftChild;
        }

        leftChild->right = node;
        node->parent = leftChild;
    }

    void fixInsertion(Node *node)
    {
        while (node != root && node->parent->color == Color::RED)
        {
            if (node->parent == node->parent->parent->left)
            {
                Node *uncle = node->parent->parent->right;

                if (uncle != nullptr && uncle->color == Color::RED)
                {
                    node->parent->color = Color::BLACK;
                    uncle->color = Color::BLACK;
                    node->parent->parent->color = Color::RED;
                    node = node->parent->parent;
                }
                else
                {
                    if (node == node->parent->right)
                    {
                        node = node->parent;
                        leftRotate(node);
                    }

                    node->parent->color = Color::BLACK;
                    node->parent->parent->color = Color::RED;
                    rightRotate(node->parent->parent);
                }
            }
            else
            {
                Node *uncle = node->parent->parent->left;

                if (uncle != nullptr && uncle->color == Color::RED)
                {
                    node->parent->color = Color::BLACK;
                    uncle->color = Color::BLACK;
                    node->parent->parent->color = Color::RED;
                    node = node->parent->parent;
                }
                else
                {
                    if (node == node->parent->left)
                    {
                        node = node->parent;
                        rightRotate(node);
                    }

                    node->parent->color = Color::BLACK;
                    node->parent->parent->color = Color::RED;
                    leftRotate(node->parent->parent);
                }
            }
        }

        root->color = Color::BLACK;
    }

    void printHelper(Node *node, std::string indent, bool last)
    {
        if (node != nullptr)
        {
            std::cout << indent;
            if (last)
            {
                std::cout << "└──";
                indent += "    ";
            }
            else
            {
                std::cout << "├──";
                indent += "│   ";
            }

            std::cout << node->data << (node->color == Color::RED ? " (Red)" : " (Black)") << std::endl;

            printHelper(node->right, indent, false);
            printHelper(node->left, indent, true);
        }
    }

public:
    RedBlackTree() : root(nullptr) {}

    void insert(int value)
    {
        Node *newNode = new Node(value);
        Node *current = root;
        Node *parent = nullptr;

        while (current != nullptr)
        {
            parent = current;
            if (value < current->data)
            {
                current = current->left;
            }
            else if (value > current->data)
            {
                current = current->right;
            }
            else
            {
                std::cout << "Duplicate values are not allowed." << std::endl;
                delete newNode;
                return;
            }
        }

        newNode->parent = parent;

        if (parent == nullptr)
        {
            root = newNode;
        }
        else if (value < parent->data)
        {
            parent->left = newNode;
        }
        else
        {
            parent->right = newNode;
        }

        fixInsertion(newNode);
    }

    void printTree()
    {
        printHelper(root, "", true);
    }
};

int main()
{
    RedBlackTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(60);
    tree.insert(70);
    tree.insert(80);
    tree.insert(90);

    tree.printTree();

    return 0;
}
