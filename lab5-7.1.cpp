#include "GameManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Queue.h"
#include <fstream>


static void saveToFile(const GameManager<Entity*>& manager, const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open file for writing.");
    }   
    
    for (const auto& entity : manager.getEntities()) {
        file << entity->serialize() << "\n";
    }
}

static void loadFromFile(GameManager<Entity*>& manager, const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open file for reading.");
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        size_t pos = line.find(',');


        std::string type = line.substr(0, pos);
        Entity* entity = new Player();

        try {
            entity->deserialize(line);
            manager.addEntity(entity);
        }
        catch (...) {
            delete entity;
            throw;
        }

    }
}



int main()
{
    // LAB 5
    std::cout << "LAB 5" << std::endl;
    GameManager<Entity*> manager;
    manager.addEntity(new Player("Hero", 100, 0));
    manager.addEntity(new Enemy("Goblin", 50, "Goblin"));
    manager.displayAll();

    Queue<int> intQueue;
    intQueue.push(2);
    intQueue.push(3);
    intQueue.push(4);
    intQueue.push(5);
    
    intQueue.displayAll();

    intQueue.pop();

    intQueue.displayAll();

    Queue<std::string> strQueue;
    strQueue.push("asd");
    strQueue.push("3");
    strQueue.push("fwffs");
    strQueue.push("gsr");

    strQueue.displayAll();

    strQueue.pop();

    strQueue.displayAll();

    // LAB 6
    std::cout << std::endl << "LAB 6" << std::endl;

    try {
        GameManager<Entity*> manager;
        manager.addEntity(new Player("Hero", -100, 0)); 
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    Queue<int> q;
    q.pop();


    // LAB 7.1
    std::cout << std::endl << "LAB 7.1" << std::endl;

    GameManager<Entity*> manager2;
    manager2.addEntity(new Player("Hero", 100, 0));
    manager2.addEntity(new Player("Hero2", 50, 50));
    saveToFile(manager2, "game_save.txt");

    GameManager<Entity*> loadedManager;
    loadFromFile(loadedManager, "game_save.txt");
    loadedManager.displayAll();


}