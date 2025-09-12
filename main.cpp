#include <iostream>
#include "include/MyVector.h"
#include "include/1DirectionList.h"
#include "include/2DirectionList.h"

int main(int, char**){

//====================================MyVector====================================
    MyVector<int> v;
    
    std::cout << "\n=================MyVector=================\n";

    for (short i = 0; i < 10; i++)
        v.push_back(i);
    
    for (auto i = v.begin(); i != v.end(); ++i)
        std::cout << *i << " ";
        
    std::cout << "\nSize: " << v.Size() << " \tCapacity: " << v.GetCapacity() << std::endl;
    
    v.erase(3);
    v.erase(5);
    v.erase(7);
    
    std::cout << std::endl;
    for (auto i = v.begin(); i != v.end(); ++i)
        std::cout << *i << " ";

    std::cout << "\nSize: " << v.Size() << "\tCapacity: " << v.GetCapacity() << std::endl;

    v.insert(0,10);
    v.insert(v.Size()/2,20);
    v.insert(v.Size(),30);

    std::cout << std::endl;

    for (auto i = v.begin(); i != v.end(); ++i)
        std::cout << *i << " ";

    std::cout << "\nSize: " << v.Size() << "\tCapacity: " << v.GetCapacity() << std::endl;

    std::cout << std::endl;

    MyVector<int> v2 = std::move(v);
    for (auto i = v2.begin(); i != v2.end(); ++i)
        std::cout << *i << " ";
    std::cout << "\nSize of v: " << v.Size() << "\tSize of v2: " << v2.Size() << std::endl << std::endl;

    MyVector<int> v3;
    v3 = std::move(v2);
    for (auto i = v3.begin(); i != v3.end(); ++i)
        std::cout << *i << " ";
    std::cout << "\nSize of v2: " << v.Size() << "\tSize of v3: " << v3.Size() << std::endl << std::endl;

//=================================1DirectionList=================================

    SingleList<int> sl;

    std::cout << "\n================SingleList================\n";

    for (int i = 0; i < 10; i++)
        sl.push_back(i);

    for (auto i = sl.begin(); i != sl.end(); ++i)
        std::cout << *i << " ";
    std::cout << "\nSize: " << sl.Size() << std::endl;

    sl.erase(3);
    sl.erase(5);
    sl.erase(7);

    std::cout << std::endl;

    for (auto i = sl.begin(); i != sl.end(); ++i)
        std::cout << *i << " ";
    std::cout << "\nSize: " << sl.Size() << std::endl;

    sl.insert(0, 10);
    sl.insert(sl.Size()/2, 20);
    sl.insert(sl.Size(), 30);

    std::cout << std::endl;

    for (auto i = sl.begin(); i != sl.end(); ++i)
        std::cout << *i << " ";
    std::cout << "\nSize: " << sl.Size() << std::endl;

    std::cout << std::endl;

    SingleList<int> sl2 = std::move(sl);
    for (auto i = sl2.begin(); i != sl2.end(); ++i)
        std::cout << *i << " ";
    std::cout << "\nSize of sl: " << sl.Size() << "    Size of sl2: " << sl2.Size() << std::endl << std::endl;

    SingleList<int> sl3;
    sl3 = std::move(sl2);
    for (auto i = sl3.begin(); i != sl3.end(); ++i)
        std::cout << *i << " ";
    std::cout << "\nSize of sl2: " << sl2.Size() << "    Size of sl3: " << sl3.Size() << std::endl << std::endl;

//=================================2DirectionList=================================

    DoubleList<int> dl;

    std::cout << "\n================DoubleList================\n";

    for (int i = 0; i < 10; i++)
        dl.push_back(i);

    for (auto i = dl.begin(); i != dl.end(); ++i)
        std::cout << *i << " ";
    std::cout << "\nSize: " << dl.Size() << std::endl;

    dl.erase(3);
    dl.erase(5);
    dl.erase(7);

    std::cout << std::endl;

    for (auto i = dl.begin(); i != dl.end(); ++i)
        std::cout << *i << " ";
    std::cout << "\nSize: " << dl.Size() << std::endl;

    dl.insert(0, 10);
    dl.insert(dl.Size()/2, 20);
    dl.insert(dl.Size(), 30);

    std::cout << std::endl;

    for (auto i = dl.begin(); i != dl.end(); ++i)
        std::cout << *i << " ";
    std::cout << "\nSize: " << dl.Size() << std::endl;

    std::cout << std::endl;

    DoubleList<int> dl2 = std::move(dl);
    for (auto i = dl2.begin(); i != dl2.end(); ++i)
        std::cout << *i << " ";
    std::cout << "\nSize of dl: " << dl.Size() << "    Size of dl2: " << dl2.Size() << std::endl << std::endl;

    DoubleList<int> dl3;
    dl3 = std::move(dl2);
    for (auto i = dl3.begin(); i != dl3.end(); ++i)
        std::cout << *i << " ";
    std::cout << "\nSize of dl2: " << dl2.Size() << "    Size of dl3: " << dl3.Size() << std::endl << std::endl;
}