#include <iostream>
using namespace std;
template <typename T>

class StackUsingArray
{
    T *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray()
    {
        capacity = 4;
        data = new T[capacity];
        nextIndex = 0;
    }

    // Size of Stack
    int size()
    {
        return nextIndex;
    }

    // Is it empty?
    bool isEmpty()
    {
        return nextIndex == 0;
    }

    // Inserting new element
    void push(T element)
    {
        if (nextIndex == capacity)
        {
            T *newData = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newData;
            // cout << "Oops, Stack is Full! :/" << endl;
            // return;
        }

        data[nextIndex] = element;
        nextIndex++;
    }

    // Deleting an element
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty! :/" << endl;
            return 0;
        }

        nextIndex--;
        return data[nextIndex];
    }

    // Topmost element

    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty! :/" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
};