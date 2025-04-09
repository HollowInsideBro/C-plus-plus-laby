#include <iostream>
#include <string>

class Weapon {
private:
    std::string name;
    int damage;
    int weight;

public:
    // Конструктор с параметрами
    Weapon(const std::string& n, int d, int w) 
        : name(n), damage(d), weight(w) {
        std::cout << "Weapon " << name << " created!\n";
    }

    // Деструктор
    ~Weapon() {
        std::cout << "Weapon " << name << " destroyed!\n";
    }

    // Метод для вывода информации
    void displayInfo() const {
        std::cout << "Weapon: " << name 
                  << ", Damage: " << damage
                  << ", Weight: " << weight 
                  << std::endl;
    }
};

int main() {
    // Создание объектов Weapon
    Weapon sword("Dragon Slayer", 45, 15);
    Weapon bow("Shadow Bow", 30, 8);
    Weapon axe("Thunder Axe", 50, 20);

    // Вывод информации об оружии
    std::cout << "\n=== Weapon Info ===\n";
    sword.displayInfo();
    bow.displayInfo();
    axe.displayInfo();

    return 0;
}