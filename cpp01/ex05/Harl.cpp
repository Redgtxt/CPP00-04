#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "Debug messages contain contextual information. Theyare mostly used for problem diagnosis" << std::endl;
}

void Harl::info(void)
{
    std::cout << "These messages contain extensive information. They are helpful for tracing program execution in a production environment." << std::endl;
}

void Harl::warning(void)
{
    std::cout << "Warning messages indicate a potential issue in the system  However, it can be handled or ignored." << std::endl;
}

void Harl::error(void)
{
    std::cout << "These messages indicate that an unrecoverable error ha occurred This is usually a critical issue that requires manual intervention." << std::endl;
}



void Harl::complain(std::string level)
{
    // array &functions
    // array levels
    // index 
    std::string names[4] = {"DEBUG","INFO","WARNING","ERROR"};
    funcs[0] =&Harl::debug;
    funcs[1] =&Harl::info;
    funcs[2] =&Harl::warning;
    funcs[3] =&Harl::error;

    for (int i = 0; i < 4; i++)
    {
        if(names[i] == level)
        {
           (this->*funcs[i])();
           return;
        }
    }
    
    std::cout << "Invalid Input" << std::endl;
}