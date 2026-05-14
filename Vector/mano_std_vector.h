#pragma once

#include <utility>
#include <stdexcept>
#include <algorithm>

template <typename T>
class Vector {
public: 
    int realloc_count = 0;
    Vector()
    {
         ReAlloc(2);
    }

    Vector(const Vector& other) 
    {
        m_Size = other.m_Size;
        m_Capacity = other.m_Capacity;
        m_Data = (T*)::operator new(m_Capacity * sizeof(T));

        for (size_t i = 0; i < m_Size; i++) {
            new(&m_Data[i]) T(other.m_Data[i]);
        }
    }

    Vector(Vector&& other) noexcept 
    {
        m_Data = other.m_Data;
        m_Size = other.m_Size;
        m_Capacity = other.m_Capacity;

        other.m_Data = nullptr;
        other.m_Size = 0;
        other.m_Capacity = 0;
    }

    Vector& operator=(const Vector& other) 
    {
        if (this == &other) return *this; 

        Clear();
        ::operator delete(m_Data, m_Capacity * sizeof(T));

        m_Size = other.m_Size;
        m_Capacity = other.m_Capacity;
        m_Data = (T*)::operator new(m_Capacity * sizeof(T));

        for (size_t i = 0; i < m_Size; i++) {
            new(&m_Data[i]) T(other.m_Data[i]);
        }

        return *this;
    }

    Vector& operator=(Vector&& other) noexcept 
    {
        if (this == &other) return *this;

        Clear();
        ::operator delete(m_Data, m_Capacity * sizeof(T));

        m_Data = other.m_Data;
        m_Size = other.m_Size;
        m_Capacity = other.m_Capacity;

        other.m_Data = nullptr;
        other.m_Size = 0;
        other.m_Capacity = 0;

        return *this;
    }

    ~Vector() 
    {
        Clear();
        ::operator delete(m_Data, m_Capacity * sizeof(T));
    }

    T* begin() { return m_Data; }
    const T* begin() const { return m_Data; }
    T* end() { return m_Data + m_Size; }
    const T* end() const { return m_Data + m_Size; }

    void PushBack(const T& value)
    {
        if (m_Size >= m_Capacity)
        {
            ReAlloc(m_Capacity + m_Capacity / 2);
        }
        new(&m_Data[m_Size]) T(value);
        m_Size++;
    }

    void PushBack(T&& value)
    {
        if (m_Size >= m_Capacity)
        {
            ReAlloc(m_Capacity + m_Capacity / 2);
        }
        new(&m_Data[m_Size]) T(std::move(value));
        m_Size++;
    }

    template<typename ... Args>
    T& EmplaceBack(Args&&... args)
    {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity / 2);

        new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
        return m_Data[m_Size++];
    }

    T* insert(T* pos, const T& value)
    {
        size_t index = pos - begin();
        if (m_Size >= m_Capacity)
        {
            ReAlloc(m_Capacity + m_Capacity / 2);
            pos = begin() + index;
        }

        if (index < m_Size)
        {
            new(&m_Data[m_Size]) T(std::move(m_Data[m_Size - 1]));
            for (size_t i = m_Size - 1; i > index; i--)
            {
                m_Data[i] = std::move(m_Data[i - 1]);
            }
            m_Data[index] = value;
        }
        else
        {
            new(&m_Data[index]) T(value);
        }

        m_Size++;
        return begin() + index;
    }

    T* erase(T* pos)
    {
        size_t index = pos - begin();
        if (index < m_Size)
        {
            m_Data[index].~T();
            for (size_t i = index; i < m_Size - 1; i++)
            {
                new(&m_Data[i]) T(std::move(m_Data[i + 1]));
                m_Data[i + 1].~T();
            }
            m_Size--;
        }
        return begin() + index;
    }
    void Assign(size_t n, const T& value) {
        Clear();
        if (n > m_Capacity) ReAlloc(n);
        for (size_t i = 0; i < n; i++) {
            new(&m_Data[i]) T(value);
        }
    m_Size = n;
    }
    void resize(size_t newSize)
    {
        if (newSize < m_Size)
        {
            for (size_t i = newSize; i < m_Size; i++)
                m_Data[i].~T();
        }
        else if (newSize > m_Size)
        {
            if (newSize > m_Capacity)
                ReAlloc(newSize);
            
            for (size_t i = m_Size; i < newSize; i++)
                new(&m_Data[i]) T();
        }
        m_Size = newSize;
    }

    void swap(Vector& other) noexcept
    {
        std::swap(m_Data, other.m_Data);
        std::swap(m_Size, other.m_Size);
        std::swap(m_Capacity, other.m_Capacity);
    }

    void PopBack()
    {
        if (m_Size > 0)
        {
            m_Size--;
            m_Data[m_Size].~T();
        }
    }

    void Clear()
    {
        for (size_t i = 0; i < m_Size; i++)
            m_Data[i].~T();

        m_Size = 0;
    }

    void Reserve(size_t newCapacity)
    {
        if (newCapacity > m_Capacity)
            ReAlloc(newCapacity);
    }

    T& at(size_t index)
    {
        if (index >= m_Size)
            throw std::out_of_range("Index out of range");
        return m_Data[index];
    }

    const T& at(size_t index) const
    {
        if (index >= m_Size)
            throw std::out_of_range("Index out of range");
        return m_Data[index];
    }

    T& front() { return m_Data[0]; }
    const T& front() const { return m_Data[0]; }
    T& back() { return m_Data[m_Size - 1]; }
    const T& back() const { return m_Data[m_Size - 1]; }
    T* data() { return m_Data; }
    const T* data() const { return m_Data; }
    bool empty() const { return m_Size == 0; }
    size_t capacity() const { return m_Capacity; }

    const T& operator[](size_t index) const { return m_Data[index]; }
    T& operator[](size_t index) { return m_Data[index]; }
    size_t Size() const { return m_Size; }

    void push_back(const T& value) { PushBack(value); }
    void push_back(T&& value) { PushBack(std::move(value)); }
    size_t size() const { return m_Size; }
    void clear() { Clear(); }
    void reserve(size_t n) { Reserve(n); }

private:

    void ReAlloc(size_t newCapacity)
    {
        realloc_count++;
        T* newBlock = (T*)::operator new(newCapacity * sizeof(T));

        size_t sizeToMove = m_Size;
        if (newCapacity < sizeToMove)
            sizeToMove = newCapacity;

        for (size_t i = 0; i < sizeToMove; i++)
        {
            new(&newBlock[i]) T(std::move(m_Data[i]));
            m_Data[i].~T();
        }

        ::operator delete(m_Data, m_Capacity * sizeof(T));
        
        m_Data = newBlock;
        m_Capacity = newCapacity;
        m_Size = sizeToMove;
    }

    T* m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;
};