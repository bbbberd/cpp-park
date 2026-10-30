#include "Player.h"
#include <iostream>

int main() {
    Player player(100);
    player.takeDamage(25);

    std::cout << "Health: " << player.getHealth() << '\n';

    return 0;
}
