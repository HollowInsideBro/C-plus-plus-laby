#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Entity {
protected:
    std::string name;
    int health;
    int attack;
    int defense;

public:
    Entity(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d) {}

    std::string getName() const { return name; }
    int getDefense() const { return defense; }
    int getHealth() const { return health; }
    int getAttack() const { return attack; }
    void setHealth(int h) { 
        health = (h < 0) ? 0 : h; // Здоровье не может быть отрицательным
    }
    virtual void hit(Entity& target) {
        int damage = attack - target.defense;
        if (damage > 0) {
            target.health -= damage;
            std::cout << name << " атакует " << target.name << " и наносит " << damage << " урона!\n";
        } else {
            std::cout << name << " атакует " << target.name << ", но это не имеет эффекта!\n";
        }
    }

    virtual void heal(int amount) {
        health += amount;
        if (health > 100) health = 100;
        std::cout << name << " восстанавливает " << amount << " HP. Текущее здоровье: " << health << "\n";
    }

    virtual void displayInfo() const {
        std::cout << "Имя: " << name << ", HP: " << health
                  << ", Атака: " << attack << ", Защита: " << defense << std::endl;
    }

    virtual ~Entity() {}
};

class Monster : public Entity {
public:
    Monster(const std::string& n, int h, int a, int d)
        : Entity(n, h, a, d) {}

    void hit(Entity& target) override {
        int damage = attack - target.getDefense();
        if (damage > 0) {
            if (rand() % 100 < 30) {
                damage += 5;
                std::cout << "Ядовитая атака! ";
            }
            target.setHealth(target.getHealth() - damage);
            std::cout << name << " атакует " << target.getName() << " и наносит " << damage << " урона!\n";
        } else {
            std::cout << name << " атакует " << target.getName() << ", но это не имеет эффекта!\n";
        }
    }

    void displayInfo() const override {
        std::cout << "Монстр: " << name << ", HP: " << health
                  << ", Атака: " << attack << ", Защита: " << defense << std::endl;
    }
};

class Boss : public Monster {
private:
    std::string specialAbility;

public:
    Boss(const std::string& n, int h, int a, int d, const std::string& ability)
        : Monster(n, h, a, d), specialAbility(ability) {}

    void hit(Entity& target) override {
        int damage = attack - target.getDefense();
        if (damage > 0) {
            if (rand() % 100 < 40) {
                damage += 15;
                std::cout << "Огненный удар! ";
            }
            target.setHealth(target.getHealth() - damage);
            std::cout << name << " атакует " << target.getName() << " и наносит " << damage << " урона!\n";
        } else {
            std::cout << name << " атакует " << target.getName() << ", но это не имеет эффекта!\n";
        }
    }

    void displayInfo() const override {
        Monster::displayInfo();
        std::cout << "Спецспособность: " << specialAbility << "\n";
    }
};

class Character : public Entity {
public:
    Character(const std::string& n, int h, int a, int d)
        : Entity(n, h, a, d) {}

    void hit(Entity& target) override {
        int damage = attack - target.getDefense();
        if (damage > 0) {
            if (rand() % 100 < 20) {
                damage *= 2;
                std::cout << "Критический удар! ";
            }
            target.setHealth(target.getHealth() - damage);
            std::cout << name << " атакует " << target.getName() << " и наносит " << damage << " урона!\n";
        } else {
            std::cout << name << " атакует " << target.getName() << ", но это не имеет эффекта!\n";
        }
    }

    void heal(int amount) override {
        health += amount * 1.2;
        if (health > 100) health = 100;
        std::cout << name << " (Персонаж) восстанавливает " << amount * 1.2 
                  << " HP. Текущее здоровье: " << health << "\n";
    }

    void displayInfo() const override {
        std::cout << "Персонаж: " << name << ", HP: " << health
                  << ", Атака: " << attack << ", Защита: " << defense << std::endl;
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));

    Character hero("Герой", 100, 25, 15);
    Monster spider("Паук", 60, 20, 10);
    Boss dragon("Дракон", 250, 35, 25, "Огненное дыхание");

    Entity* entities[] = { &hero, &spider, &dragon };

    std::cout << "=== Информация о сущностях ===\n";
    for (Entity* entity : entities) {
        entity->displayInfo();
    }

    std::cout << "\n=== Бой ===\n";
    hero.hit(spider);
    spider.hit(hero);
    dragon.hit(hero);

    std::cout << "\n=== Лечение ===\n";
    hero.heal(30);
    dragon.heal(50); // Использует метод из Entity

    return 0;
}