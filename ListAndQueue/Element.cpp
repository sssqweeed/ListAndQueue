#include "Element.h"
#include <string>

Elem::Elem(): lastName(nullptr) {  }

Elem::Elem(const char* _lastName){
    lastName = new char[strlen(_lastName)];
    strcpy(lastName, _lastName);
    
    time_t seconds = time(NULL);
    const char* temp = asctime(localtime(&seconds));
    strcpy(timeOfAddition, temp);
}

Elem::Elem(const Elem& _elem){
    lastName = new char[strlen(_elem.lastName)];
    strcpy(lastName, _elem.lastName);
    strcpy(timeOfAddition, _elem.timeOfAddition);
}

Elem::~Elem(){
    if (lastName != nullptr){
        delete[] lastName;
    }
}

void Elem::printInf(){
    printf("Last name: %s, added: %s\n", lastName, timeOfAddition);
}

Elem& Elem::operator=(const Elem& elem){
    if (this == &elem){
        return *this;
    } else {
        
        if(this->lastName != nullptr){
            delete lastName;
        }
        
        lastName = new char[strlen(elem.lastName)];
        strcpy(lastName, elem.lastName);
        strcpy(timeOfAddition, elem.timeOfAddition);
        return *this;
    }
}
