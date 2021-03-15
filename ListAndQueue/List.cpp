#include "List.h"

ListElem::ListElem(const Elem& _elem, ListElem* _next): elem(_elem), next(_next) {  }

List::List(): ptrFirstElem(nullptr), ptrLastElem(nullptr), countElements(0) {  };

List::~List(){
    while (ptrFirstElem != nullptr) {
        ListElem* temp = ptrFirstElem;
        ptrFirstElem = ptrFirstElem->next;
        delete temp;
    }
    
}

void List::pushFront(const Elem& elem){
    if (ptrLastElem == nullptr) {
        ptrLastElem = new ListElem(elem, nullptr);
        ptrFirstElem = ptrLastElem;
    }
    else {
        ptrLastElem->next = new ListElem(elem, nullptr);
        ptrLastElem = ptrLastElem->next;
    }
    countElements++;
}

void List::pushBack(const Elem& elem){
    if (ptrFirstElem == nullptr) {
        ptrFirstElem = new ListElem(elem, nullptr);
        ptrLastElem = ptrFirstElem;
    }
    else {
        ListElem* temp = ptrFirstElem;
        ptrFirstElem = new ListElem(elem, temp);
    }
    countElements++;
}

bool List::front(Elem& elem){
    if (ptrFirstElem != nullptr){
        elem = ptrFirstElem->elem;
        return true;
    }
    else {
        return false;
    }
}

bool List::back(Elem& elem){
    if (ptrLastElem != nullptr){
        elem = ptrLastElem->elem;
        return true;
    }
    else {
        return false;
    }
}

void List::print(){
    ListElem* temp = ptrFirstElem;
    std::cout << "List: \n";
    int i = 0;
    while (temp != nullptr){
        std::cout << "Elem #" << i << ": ";
        temp->elem.printInf();
        temp = temp->next;
        i++;
    }
    std::cout << "End of list\n";
}

bool List::popFront(Elem& elem){
    if (ptrFirstElem != nullptr){
        elem = ptrFirstElem->elem;
        
        ListElem* temp = ptrFirstElem->next;
        delete ptrFirstElem;
        
        ptrFirstElem = temp;
        
        countElements--;
        if (countElements == 0){
            ptrLastElem = nullptr;
        }
        return true;
    }
    else {
        printf("Warning! Pop from empty data structure\n");
        return false;
    }
}

bool List::popBack(Elem& elem){
    if (ptrFirstElem != nullptr){
        ListElem* temp = ptrFirstElem;
        
        // countElements == 1
        if (temp->next == nullptr) {
            elem = ptrFirstElem->elem;
            delete ptrFirstElem;
            
            ptrFirstElem = nullptr;
            ptrLastElem = nullptr;
        }
        else {
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            // tepm is penultimate element
            elem = temp->next->elem;
            
            delete temp->next;
            temp->next = nullptr;
            
            ptrLastElem = temp;
        }
        countElements--;
        return true;
    }
    else {
        printf("Warning! Pop from empty data structure\n");
        return false;
    }
}

bool List::isEmpty(){
    return countElements == 0;
}

unsigned int List::size(){
    return countElements;
}

void List::insert(const int position, const Elem& elem){
    if (position > countElements) {
        printf("Warning! Position is incorrect. Valid scope of the parameter is [%d, %d], but parameter = %d\n", 0, countElements, position);
        
        pushFront(elem);
        return;
    }
    if (position <= 0){
        printf("Warning! Position is incorrect. Valid scope of the parameter is [%d, %d], but parameter = %d\n", 0, countElements, position);
        pushBack(elem);
        return;
    }
    
    ListElem* copyPtr = ptrFirstElem;
    int currentPosition = 0;
    
    while (currentPosition < position - 1) {
        copyPtr = copyPtr->next;
        currentPosition++;
    }
    ListElem* temp = copyPtr->next;
    copyPtr->next = new ListElem(elem, temp);
}

bool List::erase(const int position, Elem& elem){
    
    if (position >= countElements or position < 0) {
        printf("Warning! Position is incorrect. Valid scope of the parameter is [%d, %d], but parameter = %d\n", 0, countElements - 1, position);
        return false;
    }
    
    if (position == 0){
        return popFront(elem);
    }
    if (position == countElements - 1) {
        return popBack(elem);
    }
    
    ListElem* copyPtr = ptrFirstElem;
    int currentPosition = 0;
    
    while (currentPosition < position - 1) {
        copyPtr = copyPtr->next;
        currentPosition++;
    }
    
    ListElem* temp = copyPtr->next->next;
    elem = copyPtr->next->elem;
    delete copyPtr->next;
    copyPtr->next = temp;
    return true;
}
