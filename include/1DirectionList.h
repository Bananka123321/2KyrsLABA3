#pragma once
#include <iostream>
#include <vector>

template<typename T>
class SingleList {
private:
    struct OneNode
    {
        T value;
        OneNode* next;
        OneNode(const T& val) : value(val), next(nullptr) {} 
    };
    
    OneNode* Head;
    size_t length;
    
public:
    SingleList() : Head(nullptr), length(0) {}
    SingleList(SingleList&& other) noexcept : Head(other.Head), length(other.length) {
        other.Head = nullptr;
        other.length = 0;
    }
    ~SingleList(){
        while (Head) {
            OneNode* tmp = Head;
            Head = Head->next;
            delete tmp;
        }
    }
    SingleList& operator=(SingleList&& other) noexcept{
        if (this != &other)
        {
            while (Head)
            {
                OneNode* tmp = Head;
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

    T& operator[](size_t index) {
        OneNode* cur = Head;
        for (size_t i = 0; i < index; i++)
            cur = cur->next;
        
        return cur->value;
    }

    size_t Size(){return length;}

    void push_back(const T& val) {
        OneNode* NewNode = new OneNode(val);
        if (!Head)
            Head = NewNode;
        else{
            OneNode* cur = Head;
            while (cur->next != nullptr)
                cur = cur->next;
            cur->next = NewNode;
        }
        length++;
    }
    void push_back(T&& val) {
        OneNode* NewNode = new OneNode(std::move(val));
        if (!Head)
            Head = NewNode;
        else{
            OneNode* cur = Head;
            while (cur->next != nullptr)
                cur = cur->next;
            cur->next = NewNode;
        }
        length++;
    }

    void insert(size_t index, const T& value) {
        if (index > length) return;
        OneNode* NewNode = new OneNode(value);
        if (index == 0){
            NewNode->next = Head;
            Head = NewNode;
        }
        else{
            OneNode* cur = Head;
            for (size_t i = 0; i < index - 1; i++)
                cur = cur->next;
            NewNode->next = cur->next;
            cur->next=NewNode;
        }
        length++;
    }
    void insert(size_t index, T&& value) {
        if (index > length) return;
        OneNode* NewNode = new OneNode(std::move(value));
        if (index == 0){
            NewNode->next = Head;
            Head = NewNode;
        }
        else{
            OneNode* cur = Head;
            for (size_t i = 0; i < index - 1; i++)
                cur = cur->next;
            NewNode->next = cur->next;
            cur->next=NewNode;
        }
        length++;
    }

    void erase(size_t index){
        if (index >= length) return;
        OneNode* del = Head;
        if (index == 0) {
            del = Head;
            Head = Head->next;
        }
        else{
            OneNode* cur = Head;
            for (size_t i = 0; i < index - 1; i++)
                cur = cur->next;
            del=cur->next;
            cur->next=del->next;
        }
        delete del;
        length--;
    }

     class Iterator {
        OneNode* ptr;
    public:
        Iterator(OneNode* p) : ptr(p) {}
        T& operator*() {return ptr->value;}
        T& get() {return ptr->value;}
        Iterator& operator++() {ptr = ptr->next; return *this;}
        bool operator!=(const Iterator& other) {return ptr != other.ptr;}
    };

    Iterator begin() {return Iterator(Head);}
    Iterator end() {return Iterator(nullptr);}
};