
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
#include <cstdlib>
#include "Monster.h"
#include "Character.h"

std::vector<Monster> monsters;
std::mutex monstersMutex;
std::mutex fightMutex;

void generateMonsters() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(3)); // Новый монстр каждые 3 секунды
        std::lock_guard<std::mutex> lock(monstersMutex);
        monsters.push_back(Monster("Goblin", 50, 15, 5));
        std::cout << "New monster generated!\n";
    }
}

void fight(Character& hero, Monster& monster) {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::lock_guard<std::mutex> lock(fightMutex);

        if (hero.getHealth() <= 0 || monster.getHealth() <= 0) break;

        int damageToMonster = std::max(0, hero.getAttack() - monster.getDefense());
        monster.setHealth(monster.getHealth() - damageToMonster);
        std::cout << hero.getName() << " hits " << monster.getName() << " for " << damageToMonster << " damage.\n";

        int damageToHero = std::max(0, monster.getAttack() - hero.getDefense());
        hero.setHealth(hero.getHealth() - damageToHero);
        std::cout << monster.getName() << " hits " << hero.getName() << " for " << damageToHero << " damage.\n";

        std::cout << hero.getName() << " HP: " << hero.getHealth() << " | "
            << monster.getName() << " HP: " << monster.getHealth() << "\n\n";
    }
}

int main() {
    //std::thread monsterGenerator(generateMonsters);
    //monsterGenerator.detach(); // Отсоединяем поток

    //Character hero("Hero", 100, 20, 10);

    //while (true) {
    //    std::this_thread::sleep_for(std::chrono::seconds(1));

    //    std::lock_guard<std::mutex> lock(monstersMutex);
    //    for (auto& monster : monsters) {
    //        monster.displayInfo();
    //    }
    //}

    Character hero("Hero", 100, 20, 10);
    Monster monster("Goblin", 50, 30, 0);

    std::thread fightThread(fight, std::ref(hero), std::ref(monster));
    fightThread.join();

    std::lock_guard<std::mutex> lock(fightMutex);
    if (hero.getHealth() > 0) {
        std::cout << hero.getName() << " wins!\n";
    }
    else if (monster.getHealth() > 0) {
        std::cout << monster.getName() << " wins!\n";
    }
    else {
        std::cout << "It's a draw!\n";
    }
}
