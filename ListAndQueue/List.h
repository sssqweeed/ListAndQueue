#include <iostream>
#include "Element.h"

struct ListElem{
    Elem elem;
    ListElem* next;
    
    ListElem(const Elem& _elem, ListElem* _next);
};

class List{
    
private:
    ListElem* ptrFirstElem;
    ListElem* ptrLastElem;

protected:
    unsigned int countElements;

public:
    List();
    
    ~List();
    
    void pushFront(const Elem& elem);
    
    void pushBack(const Elem& elem);
    
    bool front(Elem& elem);
    
    bool back(Elem& elem);
    
    void print();
    
    bool popFront(Elem& elem);
    
    bool popBack(Elem& elem);
    
    bool isEmpty();
    
    unsigned int size();
    
    void insert(const int position, const Elem& elem);
    
    bool erase(const int position, Elem& elem);
};



