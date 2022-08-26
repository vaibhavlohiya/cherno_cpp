#pragma once

template<typename T, size_t S>
class Array
{
public:
    /*Array(int size)
    {
        m_Data = (int*)alloca(size * sizeof(int));

    }*/
    constexpr int Size() const { return S; } // why const ? Because it is not going to change the class in anyway. READ ONLY!!!!

    T& operator[](size_t index) { return m_Data[index]; } // to input the data in the array.
    const T& operator[](size_t index) const { return m_Data[index]; } // to read the data.

    T* Data() { return m_Data; }
    const T* Data() const { return m_Data; }
private:
    T m_Data[S];
};