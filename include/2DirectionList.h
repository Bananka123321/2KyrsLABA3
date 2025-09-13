#pragma once
#include <iostream>
#include <vector>

template<typename T>
class DoubleList {
private:
    struct TwoNode
    {
        T value;
        TwoNode* prev;
        TwoNode* next;
        TwoNode(const T& val) : value(val), prev(nullptr), next(nullptr) {} 
    };
    
    TwoNode* Head;
    size_t length;
    
public:
    DoubleList() : Head(nullptr), length(0) {}
    DoubleList(DoubleList&& other) : Head(other.Head), length(other.length) {
        other.Head = nullptr;
        other.length = 0;
    }
    ~DoubleList(){
        while (Head) {
            TwoNode* tmp = Head;
            Head = Head->next;
            delete tmp;
        }
    }

    DoubleList& operator=(DoubleList&& other) {
        if (this != &other)
        {
            while (Head)
            {
                TwoNode* tmp = Head->next;
                Head = Head->next;
                delete tmp;
            }

            Head = other.Head;
            length = other.length;
            other.Head = nullptr;
            other.length = 0;
        }
        return *this;
    }

    size_t Size(){return length;}

    T& operator[](size_t index) {
        TwoNode* cur = Head;
        for (size_t i = 0; i < index; i++)
            cur = cur->next;
        
        return cur->value;
    }

    void push_back(const T& val) {
        TwoNode* NewNode = new TwoNode(val);
        if (!Head)
            Head = NewNode;
        else{
            TwoNode* cur = Head;
            while (cur->next != nullptr)
                cur = cur->next;
            cur->next = NewNode;
            NewNode->prev = cur;
        }
        length++;
    }
    void push_back(T&& val) {
        TwoNode* NewNode = new TwoNode(std::move(val));
        if (!Head)
            Head = NewNode;
        else{
            TwoNode* cur = Head;
            while (cur->next != nullptr)
                cur = cur->next;
            cur->next = NewNode;
            NewNode->prev = cur;
        }
        length++;
    }

    void insert(size_t index, const T& value) {
        if (index > length) return;
        TwoNode* NewNode = new TwoNode(value);
        if (index == 0) {
            NewNode->next = Head;
            if (Head != nullptr)
                Head->prev = NewNode;
            Head = NewNode;
            NewNode->prev = nullptr;
        }
        else{
            TwoNode* cur = Head;
            for (size_t i = 0; i < index - 1; i++)
                cur = cur->next;

            NewNode->next = cur->next;
            NewNode->prev = cur;

            if (cur->next != nullptr)
                cur->next->prev = NewNode;

            cur->next = NewNode;
        }
        length++;
    }
    void insert(size_t index, T&& value) {
        if (index > length) return;
        TwoNode* NewNode = new TwoNode(std::move(value));
        if (index == 0) {
            NewNode->next = Head;
            if (Head != nullptr)
                Head->prev = NewNode;
            Head = NewNode;
            NewNode->prev = nullptr;
        }
        else{
            TwoNode* cur = Head;
            for (size_t i = 0; i < index - 1; i++)
                cur = cur->next;

            NewNode->next = cur->next;
            NewNode->prev = cur;

            if (cur->next != nullptr)
                cur->next->prev = NewNode;

            cur->next = NewNode;
        }
        length++;
    }

    void erase(size_t index){
        if (index >= length) return;
        TwoNode* del = Head;
        if (index == 0) {
            del = Head;
            Head = Head->next;
            if (Head != nullptr)
                Head->prev = nullptr;
        }
        else {
            TwoNode* cur = Head;
            for (size_t i = 0; i < index - 1; i++)
                cur = cur->next;
            del = cur->next;

            cur->next = del->next;
            if (del->next != nullptr)
                del->next->prev = cur;
        }

        delete del;
        length--;
    }

    class Iterator {
        TwoNode* ptr;
    public:
        Iterator(TwoNode* p) : ptr(p) {}
        T& operator*() {return ptr->value;}
        T& get() {return ptr->value;}
        Iterator& operator++() {ptr = ptr->next; return *this;}
        bool operator!=(const Iterator& other) {return ptr != other.ptr;}
    };

    Iterator begin() {return Iterator(Head);}
    Iterator end() {return Iterator(nullptr);}
};