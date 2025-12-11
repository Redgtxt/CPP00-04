#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << this->getType() << " Constructor Called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "Copy assignment WrongCat operator called" << std::endl;

    if(this != &other)
    {
        this->type = other.type;
    }
    
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "miau miau miau" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
    *this = obj;
}


WrongCat::~WrongCat() 
{
    std::cout << this->getType() << " destructor called" << std::endl;
}