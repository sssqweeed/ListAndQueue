#include <iostream>
#include "Queue.h"

int main(int argc, const char * argv[]) {
    
    Queue q(3);
    Elem elem;
    
    std::cout << q.isEmpty() << "\n";
    
    q.print();
    
    q.push("Misha");
    q.push("Sasha");
    
    q.print();
    
    q.pop(elem);
    elem.printInf();
    q.pop(elem);
    elem.printInf();
    
    q.push("Misha");
    q.push("Sasha");
    q.push("Pasha");
    q.push("Bob");
    
    q.print();
    
    std::cout << q.isFull() << " " << q.size() << "\n";
    
    q.pop(elem);
    q.pop(elem);
    q.pop(elem);
    q.pop(elem);
    q.pop(elem);
    
    q.print();
    
    return 0;
}


