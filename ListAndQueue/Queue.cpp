#include "Queue.h"
unsigned int Queue::numberOfPeopleInAllQueues = 0;

Queue::Queue(unsigned int _maxSize): maxSize(_maxSize){  }

Queue::~Queue(){  }

void Queue::push(const Elem & elem){
    if (maxSize > countElements){
        List::pushBack(elem);
        numberOfPeopleInAllQueues++;
    } else {
        printf("Queue is full\n");
    }
}

bool Queue::front(Elem& elem){
    return List::front(elem);
}

bool Queue::pop(Elem& elem){
    const bool isSuccessful = List::popFront(elem);
    if (isSuccessful){
        numberOfPeopleInAllQueues--;
    }
    return isSuccessful;
}

bool Queue::isEmpty(){
    return List::isEmpty();
}

unsigned int Queue::size(){
    return List::size();
}

bool Queue::isFull(){
    return maxSize == countElements;
}

void Queue::print(){
    printf("Queue information:\n");
    printf("Number of people in all queues: %d\n", numberOfPeopleInAllQueues);
    List::print();
}
