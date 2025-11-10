#pragma once
#include <iostream>
#include <string>

class Zombie
{
private:
    std::string name;

public:
    void announce();

   
    Zombie(); //Default Constructor
    Zombie(std::string name);//Construtor que cria com um nome
    ~Zombie(); // Destrutor 

    void setName(std::string name) { this->name = name; }
    void getName() const { std::cout << name << std::endl; }
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );
Zombie* zombieHorde(int N, std::string name);
