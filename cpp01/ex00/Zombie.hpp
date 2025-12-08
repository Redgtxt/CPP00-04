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
    ~Zombie();

    void setName(std::string name);
    void getName() const;
};
