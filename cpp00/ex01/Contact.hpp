#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

class Contact
{
private:
    std::string FirstName;
    std::string LastName;
    std::string NickName;
    std::string PhoneNumber;
    std::string DarkestSecret;

public:
    std::string truncateString(const std::string &str) const;
    void printTableRow(int idx) const;
    void printFullInfo() const;
    void printInfo(int idx) const;

    void setFirstName(const std::string &name) { FirstName = name; }
    std::string getFirstName() const { return FirstName; }

    void setLastName(const std::string &name) { LastName = name; }
    std::string getLastName() const { return LastName; }

    void setNickName(const std::string &name) { NickName = name; }
    std::string getNickName() const { return NickName; }

    void setPhoneNumber(const std::string &number) { PhoneNumber = number; }
    std::string getPhoneNumber() const { return PhoneNumber; }

    void setDarkestSecret(const std::string &secret) { DarkestSecret = secret; }
    std::string getDarkestSecret() const { return DarkestSecret; }
};
