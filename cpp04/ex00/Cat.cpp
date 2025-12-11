#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << this->getType() << " Constructor Called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Copy assignment Cat operator called" << std::endl;

    if(this != &other)
    {
        this->type = other.type;
    }
    
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "miau miau miau" << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    *this = obj;
}


Cat::~Cat() 
{
    std::cout << this->getType() << " destructor called" << std::endl;
}