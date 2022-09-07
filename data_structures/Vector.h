#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template<typename T>
class Vector
{
public:
    Vector()
    {
        // allocate memory for 2 elements
        ReAlloc(2);
    }

    void PushBack(const T& value)
    {
        if (m_size > m_Capacity)
            ReAlloc(m_Capacity + m_Capacity);

        m_Data[m_size] = value;
        m_size++;
    }

    size_t Size() const { return m_size; }

    const T& operator[](size_t index) const { return m_Data[index]; }
    T& operator[](size_t index) { return m_Data[index]; }
    
private:
    void ReAlloc(size_t newCapacity)
    {
        // 1. Allocate a new block of memory
        // 2. copy/move old elements into new block
        // 3. delete

        T* newBlock = new T[newCapacity]; // array of variable T

        if (newCapacity < m_size) // if we were to downsize the memory allocation.
            m_size = newCapacity;

        for (size_t i = 0; i < m_size; i++)
            newBlock[i] = m_Data[i];
        
        delete[] m_Data;
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }
private:
    T* m_Data = nullptr;

    size_t m_size = 0;
    size_t m_Capacity = 0;
};

#endif