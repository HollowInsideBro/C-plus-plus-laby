#include "Person.h"

int main()
{
    Person person;

    // Устанавливаем значения с помощью сеттеров
    person.setName("John Doe");
    person.setAge(25);
    person.setEmail("john.doe@example.com");
    person.setAddress("Pushkina street");

    // Выводим информацию с помощью геттеров
    std::cout << "Name: " << person.getName() << std::endl;
    std::cout << "Age: " << person.getAge() << std::endl;
    std::cout << "Email: " << person.getEmail() << std::endl;
    std::cout << "Address: " << person.getAddress() << std::endl;

    // Пытаемся установить некорректные значения
    person.setName(""); // Ошибка: имя не может быть пустым
    person.setAge(150); // Ошибка: возраст должен быть от 0 до 120
    person.setEmail("invalid-email"); // Ошибка: некорректный email
    person.setAddress(""); // Ошибка: пустой адрес 

    // Выводим информацию о человеке
    person.displayInfo();
}
