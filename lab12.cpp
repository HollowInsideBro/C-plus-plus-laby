#include <iostream>
#include <string>

class Entity {
protected:
    std::string name;
    int health;

public:
    Entity(const std::string& n, int h) : name(n), health(h) {}

    virtual void displayInfo() const {
        std::cout << "Name: " << name << ", HP: " << health << std::endl;
    }

    virtual ~Entity() {}
};

class Enemy : public Entity {
protected:
    std::string type;

public:
    Enemy(const std::string& n, int h, const std::string& t)
        : Entity(n, h), type(t) {}

    void displayInfo() const override {
        Entity::displayInfo();
        std::cout << "Type: " << type << std::endl;
    }
};

// 1. Создаем класс Boss, наследующий от Enemy
class Boss : public Enemy {
private:
    std::string specialAbility; // Уникальное свойство

public:
    // Конструктор с параметрами для всех полей
    Boss(const std::string& n, int h, const std::string& t, const std::string& ability)
        : Enemy(n, h, t), specialAbility(ability) {}

    // 2. Переопределяем метод displayInfo()
    void displayInfo() const override {
        Enemy::displayInfo(); // Вызываем метод базового класса (Enemy)
        std::cout << "Special Ability: " << specialAbility << std::endl;
    }
};

int main() {
    // 3. Создаем объект Boss и демонстрируем его работу
    Boss finalBoss("Dragon", 500, "Dragon", "Fire Breath");
    finalBoss.displayInfo();

    return 0;
}