#include "Enemy.h"
#include "Player.h"
#include "Inventory.h"

int main()
{
    // Массив умных указателей на базовый класс
    std::unique_ptr<Entity> entities[] = {
        std::make_unique<Player>("Hero", 100, 0),
        std::make_unique<Enemy>("Goblin", 50, "Goblin")
    };

    // Полиморфизм и автоматическое управление памятью
    for (const auto& entity : entities) {
        entity->displayInfo();
    }

    Inventory inventory;
    inventory.addItem("sword");
    inventory.addItem("potion");
    inventory.addItem("helmet");
    
    inventory.displayInventory();
}

