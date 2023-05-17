#ifndef DYNAMIC_H
#define DYNAMIC_H

#include <iostream>

template<class T>
class DynamicArray
{

private:
    T *data;
    int size;

public:
    DynamicArray()
    {
        this->size = 0;
        data = new T[0];
    }

    DynamicArray(T arr[], int size)
    {
        this->size = size;        
        data = new T[size];
        for (int i = 0; i < size; ++i)
        {
            data[i] = arr[i];
        }
    }

    DynamicArray(const DynamicArray &o)
    {
        this->size = o.size;
        data = new T[o.size];
        for (int i = 0; i < o.size; ++i)
        {
            data[i] = o.data[i];
        }
    }

    void print() const
    {
        std ::cout << "[ ";
        for (int i = 0; i < size; ++i)
        {
            std::cout << data[i] << " ";
        }
        std ::cout << "]" << std::endl;
    }

    ~DynamicArray()
    {
        delete[] data;
    }

    void pushback(T value)
    {
        T *aux = new T[size + 1];

        // Fill in the original values
        for (int i = 0; i < size; ++i)
        {
            aux[i] = data[i];
        }

        // Add to the last the requested value 
        aux[size] = value;
        delete[] data;
        data = aux;
        ++size;
    }

    void insert(T value, int pos)
    {
        if (pos >= size)
        {
            pushback(value);
            return;
        }

        // Fill in values until before the requested position
        T *aux = new T[size + 1];
        for (int i = 0; i < pos; ++i)
        {
            aux[i] = data[i];
        }

        // Add the requested value
        aux[pos] = value;

        // Add the remaining values
        for (int i = pos; i < size; ++i)
        {
            aux[i + 1] = data[i];
        }
        delete[] data;
        data = aux;
        ++size;
    }

    void remove(int pos)
    {
        // If it is out of range, the program closes
        if (pos < 0 || pos >= size)
        {
            return;
        }

        // Decrease the array size
        T *aux = new T[size - 1];

        // Fill in values until before the requested position
        for (int i = 0; i < pos; ++i)
        {
            aux[i] = data[i];
        }

        // Fill values after the requested position
        for (int i = pos + 1; i < size; ++i)
        {
            aux[i - 1] = data[i];
        }
        delete[] data;
        data = aux;
        --size;
    }
};

#endif