#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int front;
    int rear;
    int capacity;

public:
    Queue(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }
    ~Queue()
    {
        delete[] arr;
    }
    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        rear++;
        arr[rear] = data;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        front++;
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
    bool isEmpty()
    {
        return front > rear;
    }
    bool isFull()
    {
        return rear - front == capacity - 1;
    }
    void print()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    // Printing the queue
    q.print(); // Output: 1 2 3 4 5

    // Removing an element from the queue
    q.dequeue();
    q.print(); // Output: 2 3 4 5

    // Adding a new element to the queue
    q.enqueue(6);
    q.print(); // Output: 2 3 4 5 6

    // Peeking at the front element of the queue
    cout << q.peek() << endl; // Output: 2

    return 0;
}