#pragma once
#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;
    std::string email;
    std::string address;

public:
    // Геттеры
    std::string getName() const;

    int getAge() const;

    std::string getEmail() const;

    std::string getAddress() const;

    // Сеттеры
    void setName(const std::string& newName);

    void setAge(int newAge);

    void setEmail(const std::string& newEmail);

    void setAddress(const std::string& newAddress);

    // Метод для вывода информации о человеке
    void displayInfo() const;
};


