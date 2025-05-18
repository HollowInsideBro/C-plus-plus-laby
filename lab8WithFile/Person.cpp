#include "Person.h"

std::string Person::getName() const
{
    return name;
}

int Person::getAge() const
{
    return age;
}

std::string Person::getEmail() const
{
    return email;
}

std::string Person::getAddress() const
{
    return address;
}

void Person::setName(const std::string& newName)
{
    if (!newName.empty()) {
        name = newName;
    }
    else {
        std::cerr << "Error: Name cannot be empty!" << std::endl;
    }
}

void Person::setAge(int newAge)
{
    if (newAge >= 0 && newAge <= 120) {
        age = newAge;
    }
    else {
        std::cerr << "Error: Age must be between 0 and 120!" << std::endl;
    }
}

void Person::setEmail(const std::string& newEmail)
{
    if (newEmail.find('@') != std::string::npos) {
        email = newEmail;
    }
    else {
        std::cerr << "Error: Invalid email format!" << std::endl;
    }
}

void Person::setAddress(const std::string& newAddress)
{
    if (!newAddress.empty()) {
        address = newAddress;
    }
    else {
        std::cerr << "Error: Address cannot be empty!" << std::endl;
    }
}

void Person::displayInfo() const
{
    std::cout << "Name: " << name << ", Age: " << age << ", Email: " << email << ", Address: " << address << std::endl;
}

