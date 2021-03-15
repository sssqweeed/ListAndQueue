struct Elem{
    char* lastName;
    char timeOfAddition[26];
    
    Elem();
    
    Elem(const char* _lastName);
    
    Elem(const Elem& _elem);
    
    ~Elem();
    
    void printInf();
    
    Elem& operator=(const Elem& elem);
};

