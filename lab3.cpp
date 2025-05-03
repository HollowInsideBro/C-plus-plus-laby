#include "Character.h"
#include "Weapon.h"

int main()
{
    Character hero1("Hero", 100, 20, 10);
    Character hero2("Hero", 100, 20, 10);
    Character hero3("Warrior", 150, 25, 15);

    if (hero1 == hero2) {
        std::cout << "Hero1 and Hero2 are the same!\n";
    }
    if (!(hero1 == hero3)) {
        std::cout << "Hero1 and Hero3 are different!\n";
    }

    std::cout << hero1 << std::endl;

    Weapon sword("sword", 10);
    Weapon axe("axe", 8);

    if (sword > axe) {
        std::cout << "Sword is better than axe" << std::endl;
    }

    Weapon swordaxe = sword + axe;

    std::cout << swordaxe << std::endl;

}
