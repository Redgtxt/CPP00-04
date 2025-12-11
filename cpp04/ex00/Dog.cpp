#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << this->getType() << " Constructor Called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Copy assignment Dog operator called" << std::endl;

    if(this != &other)
    {
        this->type = other.type;
    }
    
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Cao cao cao" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    *this = obj;
}


Dog::~Dog() 
{
    std::cout << this->getType() << " destructor called" << std::endl;
}