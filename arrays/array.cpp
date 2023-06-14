#include <iostream>

using namespace std;

class MyArray
{
private:
    int *data;
    int size;

public:
    MyArray(int size)
    {
        this->size = size;
        data = new int[size];
    }
    ~MyArray()
    {
        delete[] data;
    }
    int &operator[](int index)
    {
        return data[index];
    }
    int getSize()
    {
        return size;
    }
};

int main()
{
    MyArray my_array(5);
    my_array[0] = 1;
    my_array[1] = 2;
    my_array[2] = 3;
    my_array[3] = 4;
    my_array[4] = 5;

    // Accessing elements of the array
    cout << my_array[0] << endl; // Output: 1
    cout << my_array[2] << endl; // Output: 3

    // Modifying elements of the array
    my_array[0] = 10;
    cout << my_array[0] << endl; // Output: 10

    return 0;
}