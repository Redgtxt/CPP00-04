#include "PhoneBook.hpp"

int main()
{
    std::string prompt;
    PhoneBook pb;
    while (true)
    {
        std::cout << "Please enter a command (ADD, SEARCH, EXIT): ";
        if(!std::getline(std::cin,prompt)){
            std::cout << "\nEOF detected. Exiting program." << std::endl;
            break;
        }
        if(pb.checkForComand(prompt) == 3)
            break;
    }
}