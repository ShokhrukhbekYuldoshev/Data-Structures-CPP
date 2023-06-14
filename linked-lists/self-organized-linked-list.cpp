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

class SelfOrganizingLinkedList
{
private:
    Node *head;

public:
    SelfOrganizingLinkedList()
    {
        head = nullptr;
    }
    ~SelfOrganizingLinkedList()
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
        if (head == nullptr)
        {
            head = node;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
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
    void access(int data)
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->data == data)
        {
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            if (current->next->data == data)
            {
                Node *temp = current->next;
                current->next = current->next->next;
                temp->next = head;
                head = temp;
                return;
            }
            current = current->next;
        }
    }
};

int main()
{
    SelfOrganizingLinkedList list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    // Printing the list
    list.print(); // Output: 1 2 3 4 5

    // Accessing an element in the list
    list.access(3);
    list.print(); // Output: 3 1 2 4 5

    return 0;
}