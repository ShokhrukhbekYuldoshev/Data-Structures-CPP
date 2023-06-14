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

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList()
    {
        head = nullptr;
    }
    ~CircularLinkedList()
    {
        if (head == nullptr)
        {
            return;
        }
        Node *current = head->next;
        while (current != head)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
    }
    void add(int data)
    {
        Node *node = new Node(data);
        if (head == nullptr)
        {
            head = node;
            head->next = head;
        }
        else
        {
            Node *current = head;
            while (current->next != head)
            {
                current = current->next;
            }
            current->next = node;
            node->next = head;
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
            if (head->next == head)
            {
                head = nullptr;
            }
            else
            {
                Node *current = head;
                while (current->next != head)
                {
                    current = current->next;
                }
                head = head->next;
                current->next = head;
            }
            delete temp;
            return;
        }
        Node *current = head;
        while (current->next != head)
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
        if (head == nullptr)
        {
            return;
        }
        Node *current = head;
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

int main()
{
    CircularLinkedList list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    // Printing the list
    list.print(); // Output: 1 2 3 4 5

    // Removing an element from the list
    list.remove(3);
    list.print(); // Output: 1 2 4 5

    return 0;
}