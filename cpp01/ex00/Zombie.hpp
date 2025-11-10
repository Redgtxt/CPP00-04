#pragma once
#include <iostream>
#include <string>

class Zombie
{
private:
    std::string name;

public:
    void announce();

    Zombie(std::string name);
    ~Zombie(); // Destrutor adicionado!

    void setName(std::string name) { this->name = name; }
    void getName() const { std::cout << name << std::endl; }
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );