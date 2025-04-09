#include <iostream>
#include <string>

class Character {
private:
    std::string name;
    int health;
    int attack;
    int defense;

public:
    Character(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d) {}

    int getHealth() const {
        return health;
    }

    void displayInfo() const {
        std::cout << "Name: " << name << ", HP: " << health
                  << ", Attack: " << attack << ", Defense: " << defense << std::endl;
    }

    void attackEnemy(Character& enemy) {
        int damage = attack - enemy.defense;
        if (damage > 0) {
            enemy.health -= damage;
            std::cout << name << " attacks " << enemy.name << " for " << damage << " damage!" << std::endl;
        } else {
            std::cout << name << " attacks " << enemy.name << ", but it has no effect!" << std::endl;
        }
    }

    void heal(int amount) {
        health += amount;
        if (health > 100) {
            health = 100;
        }
    }

    void takeDamage(int amount) {
        health -= amount;
        if (health < 0) {
            health = 0;
        }
    }
};

int main() {
    Character hero("Hero", 100, 20, 10);
    Character monster("Goblin", 50, 15, 5);

    // Исходное состояние
    hero.displayInfo();
    monster.displayInfo();

    // Герой атакует монстра
    hero.attackEnemy(monster);
    monster.displayInfo();

    // Монстр лечится
    monster.heal(20);
    monster.displayInfo();

    // Проверка методов heal и takeDamage
    hero.heal(10); // Здоровье героя остается 100
    hero.displayInfo();

    hero.takeDamage(50); // Здоровье героя: 100 - 50 = 50
    hero.displayInfo();

    hero.heal(30); // Здоровье героя: 50 + 30 = 80
    hero.displayInfo();

    hero.heal(30); // Здоровье героя: 80 + 30 = 110 → 100
    hero.displayInfo();

    hero.takeDamage(150); // Здоровье героя: 100 - 150 = 0
    hero.displayInfo();

    // Дополнительные проверки
    Character test("Test", 150, 0, 0);
    test.displayInfo();

    test.heal(10); // Здоровье: 150 + 10 = 160 → 100
    test.displayInfo();

    test.takeDamage(20); // Здоровье: 100 - 20 = 80
    test.displayInfo();

    test.heal(50); // Здоровье: 80 + 50 = 130 → 100
    test.displayInfo();

    return 0;
}