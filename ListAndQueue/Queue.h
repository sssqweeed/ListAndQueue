#include "List.h"

class Queue : private List{
private:
    const unsigned int maxSize;
    static unsigned int numberOfPeopleInAllQueues;
    
public:
    explicit Queue(unsigned int _maxSize = 10);
    
    ~Queue();
    
    void push(const Elem& elem);
    
    bool front(Elem& elem);
    
    bool pop(Elem& elem);
    
    bool isEmpty();
    
    unsigned int size();
    
    bool isFull();
    
    void print();
};
