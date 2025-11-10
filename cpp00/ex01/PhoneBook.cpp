#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0) {};

PhoneBook::~PhoneBook() {};

void PhoneBook::addContact(const Contact &contact)
{
    list[count % 8] = contact;
    count++;
}

int PhoneBook::getContactCount() const
{
    return (count < 8) ? count : 8;
}

const Contact &PhoneBook::getContact(int idx) const
{
    return list[idx];
}

bool isAllDigits(const std::string &s)
{
    if (s.empty())
        return false;
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (!std::isdigit((s[i])))
            return false;
    }
    return true;
}

void promptAndSet(const std::string &fieldName, void (Contact::*setter)(const std::string &), Contact &contact)
{
    std::string input;
    while (true)
    {
        std::cout << fieldName << ": ";
        if (!std::getline(std::cin, input))
        {
            std::cout << "\nEOF detected. Exiting program." << std::endl;
            exit(0);
        }

        // Check for empty input
        if (input.empty())
        {
            std::cout << "Field cannot be empty. Please try again." << std::endl;
            continue;
        }

        // Check for invalid characters
        bool valid = true;
        for (size_t i = 0; i < input.size(); ++i)
        {
            // Check if character is printable and not a tab
            if (!isprint(static_cast<unsigned char>(input[i])) || input[i] == '\t')
            {
                valid = false;
                break;
            }
        }

        if (!valid)
        {
            std::cout << "Input contains invalid characters or tabs. Please try again." << std::endl;
            continue;
        }

        // If we reach here, input is valid
        break;
    }

    (contact.*setter)(input);
}

void PhoneBook::displayContactsTable()
{
    int total = getContactCount();

    // Print header
    std::cout << "|" << std::setw(10) << std::right << "Index";
    std::cout << "|" << std::setw(10) << std::right << "First Name";
    std::cout << "|" << std::setw(10) << std::right << "Last Name";
    std::cout << "|" << std::setw(10) << std::right << "Nickname";
    std::cout << "|" << std::endl;

    // Print contacts
    for (int i = 0; i < total; ++i)
    {
        getContact(i).printTableRow(i);
    }
}

int PhoneBook::checkForComand(std::string command)
{
    if (command == "ADD")
    {
        Contact info;
        promptAndSet("First Name", &Contact::setFirstName, info);
        promptAndSet("Last Name", &Contact::setLastName, info);
        promptAndSet("NickName", &Contact::setNickName, info);
        promptAndSet("PhoneNumber", &Contact::setPhoneNumber, info);
        promptAndSet("Darkest Secret", &Contact::setDarkestSecret, info);
        addContact(info);
        return 1;
    }
    else if (command == "SEARCH")
    {
        int total = getContactCount();
        if (total == 0)
        {
            std::cout << "No contacts found." << std::endl;
        }
        else
        {
            displayContactsTable();

            std::string indexInput;

            while (true)
            {
                std::cout << "Enter the index of the contact to display: ";
                if (!std::getline(std::cin, indexInput))
                {
                    std::cout << "\nEOF detected. Exiting program." << std::endl;
                    exit(0);
                }

                if (!isAllDigits(indexInput))
                {
                    std::cout << "Invalid input. Please enter a valid number." << std::endl;
                    continue;
                }

                int index = std::atoi(indexInput.c_str());
                if (index >= 0 && index < total)
                {
                    getContact(index).printFullInfo();
                    break;
                }
                else
                {
                    std::cout << "Invalid index. Please enter a number between 0 and "
                              << (total - 1) << "." << std::endl;
                }
            }
        }
        return 2;
    }
    else if (command == "EXIT")
    {
        return 3;
    }
    return 0;
}
