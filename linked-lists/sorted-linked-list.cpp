#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class SortedLinkedList
{
private:
    Node *head;

public:
    SortedLinkedList()
    {
        head = nullptr;
    }
    ~SortedLinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }
    void add(int data)
    {
        Node *node = new Node(data);
        if (head == nullptr || data < head->data)
        {
            node->next = head;
            head = node;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr && current->next->data < data)
            {
                current = current->next;
            }
            node->next = current->next;
            current->next = node;
        }
    }
    void remove(int data)
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->data == data)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            if (current->next->data == data)
            {
                Node *temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }
    void print()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    SortedLinkedList list;
    list.add(3);
    list.add(1);
    list.add(4);
    list.add(2);
    list.add(5);

    // Printing the list
    list.print(); // Output: 1 2 3 4 5

    // Removing an element from the list
    list.remove(3);
    list.print(); // Output: 1 2 4 5

    return 0;
}