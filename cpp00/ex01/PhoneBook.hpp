#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact list[8];
    int count;

public:
    PhoneBook();
    ~PhoneBook();
    int checkForComand(std::string command);
    void addContact(const Contact &contact);
    int getContactCount() const;
    const Contact &getContact(int idx) const;

    void displayContactsTable();
};
