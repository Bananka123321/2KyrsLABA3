#pragma once
#include <iostream>
#include <vector>

template<typename T>
class MyVector {
private:
    T* Data;
    size_t capacity, length;
    
    void Resize(){
        capacity*=2;
        T* newData = new T[capacity];
        for (size_t i = 0; i < length; i++)
            newData[i] = Data[i];
        delete[] Data;
        Data = newData;
    }

public:
    
    MyVector() : Data(new T[1]), capacity(1), length(0){}
    MyVector(MyVector&& other) : Data(other.Data), capacity(other.capacity), length(other.length) {
        other.Data = nullptr;
        other.capacity = 0;
        other.length = 0;
    }

    ~MyVector() {delete[] Data;}

    MyVector& operator=(MyVector&& other) {
    if (this != &other) {
        delete[] Data;
        Data = other.Data;
        capacity = other.capacity;
        length = other.length;

        other.Data = nullptr;
        other.capacity = 0;
        other.length = 0;
    }
    return *this;
}

    size_t Size(){return length;}
    size_t GetCapacity(){return capacity;}
    
    void push_back(const T& value) {
        if (length == capacity)
            Resize();
        Data[length] = value;
        length++;
    }
    void push_back(T&& value) {
        if (length == capacity)
            Resize();
        Data[length] = std::move(value);
        length++;
    }

    T& operator[](size_t index) {return Data[index];}

    void insert(size_t index, const T& value) {
        if (index > length) return;
        if (length==capacity)
            Resize();
        for (size_t i = length; i > index; i--)
            Data[i]=Data[i-1];
        Data[index] = value;
        length++;
    }
    void insert(size_t index, T&& value) {
        if (index > length) return;
        if (length==capacity)
            Resize();
        for (size_t i = length; i > index; i--)
            Data[i]=Data[i-1];
        Data[index] = std::move(value);
        length++;
    }

    void erase(size_t index) {
        if (index >= length) return;
        for (size_t i = index; i < length - 1; i++)
            Data[i] = Data[i + 1];
        length--;
    }

    class Iterator {
        T* ptr;
    public:
        Iterator(T* p) : ptr(p) {}
        T& operator*() {return *ptr;}
        T& get() {return *ptr;}
        Iterator& operator++() {++ptr; return *this;}
        bool operator!=(const Iterator& other) {return ptr != other.ptr;}
    };

    Iterator begin() {return Iterator(Data);}
    Iterator end() {return Iterator(Data + length);}
};

