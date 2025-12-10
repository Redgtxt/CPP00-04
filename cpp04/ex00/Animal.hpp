#pragma once
#include <iostream>

class Animal
{

protected:
    std::string type;//tipo de animal
    
public:
    Animal();
    Animal(std::string name);
    Animal(const Animal &obj);
    Animal& operator=(const Animal& other);
    virtual ~Animal();
    virtual void makeSound() const;
    const std::string& getType(void) const;
};

