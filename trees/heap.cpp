#include <vector>
#include <iostream>

class BinaryHeap
{
private:
    std::vector<int> heap;

    void bubbleUp(int index)
    {
        while (index > 0)
        {
            int parentIndex = (index - 1) / 2;
            if (heap[index] < heap[parentIndex])
            {
                std::swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    void bubbleDown(int index)
    {
        while (index < heap.size())
        {
            int leftChildIndex = 2 * index + 1;
            int rightChildIndex = 2 * index + 2;
            int minIndex = index;

            if (leftChildIndex < heap.size() && heap[leftChildIndex] < heap[minIndex])
            {
                minIndex = leftChildIndex;
            }

            if (rightChildIndex < heap.size() && heap[rightChildIndex] < heap[minIndex])
            {
                minIndex = rightChildIndex;
            }

            if (minIndex != index)
            {
                std::swap(heap[index], heap[minIndex]);
                index = minIndex;
            }
            else
            {
                break;
            }
        }
    }

public:
    void insert(int value)
    {
        heap.push_back(value);
        bubbleUp(heap.size() - 1);
    }

    int extractMin()
    {
        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        bubbleDown(0);
        return min;
    }

    int peek()
    {
        return heap[0];
    }

    bool isEmpty()
    {
        return heap.empty();
    }
};

int main()
{
    BinaryHeap heap;
    heap.insert(5);
    heap.insert(3);
    heap.insert(7);
    heap.insert(1);
    heap.insert(2);
    heap.insert(6);
    heap.insert(4);

    while (!heap.isEmpty())
    {
        std::cout << heap.extractMin() << " ";
    }

    return 0;
}