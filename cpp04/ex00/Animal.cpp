#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(std::string name) : type(name)
{
    std::cout << "Animal with type constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Copy assignment Animal operator called" << std::endl;

    if(this != &other)
    {
        this->type = other.type;
    }
    
    return *this;
}


Animal::Animal(const Animal &obj)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    *this = obj;
}



const std::string& Animal::getType(void) const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "No Sound :(" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor caleed" << std::endl;
}
