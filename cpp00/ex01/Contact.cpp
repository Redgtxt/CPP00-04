#include "Contact.hpp"

std::string Contact::truncateString(const std::string &str) const
{
    if (str.length() > 10)
    {
        return str.substr(0, 9) + ".";
    }
    return str;
}

void Contact::printTableRow(int idx) const
{
    std::cout << "|" << std::setw(10) << std::right << idx;
    std::cout << "|" << std::setw(10) << std::right << truncateString(FirstName);
    std::cout << "|" << std::setw(10) << std::right << truncateString(LastName);
    std::cout << "|" << std::setw(10) << std::right << truncateString(NickName);
    std::cout << "|" << std::endl;
}

void Contact::printFullInfo() const
{
    std::cout << "First Name: " << FirstName << std::endl;
    std::cout << "Last Name: " << LastName << std::endl;
    std::cout << "NickName: " << NickName << std::endl;
    std::cout << "PhoneNumber: " << PhoneNumber << std::endl;
    std::cout << "Darkest Secret: " << DarkestSecret << std::endl;
}

void Contact::printInfo(int idx) const
{
    std::cout << "Index: " << idx << std::endl;
    std::cout << "First Name: " << FirstName << std::endl;
    std::cout << "Last Name: " << LastName << std::endl;
    std::cout << "NickName: " << NickName << std::endl;
    std::cout << "PhoneNumber: " << PhoneNumber << std::endl;
    std::cout << "Darkest Secret: " << DarkestSecret << std::endl;
}