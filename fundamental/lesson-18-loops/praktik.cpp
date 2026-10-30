#include <array>
#include <iostream>

int main() {
    std::array<int, 5> enemyHP = {100, 0, 45, 15, 0};

    int aliveCount = 0;
    int deadCount = 0;

    for (int hp : enemyHP) {
        if (hp <= 0) {
            ++deadCount;
            continue;
        }

        ++aliveCount;

        if (hp < 30) {
            std::cout << "Musuh terluka parah: " << hp << " HP.\n";
        } else {
            std::cout << "Musuh masih bertarung: " << hp << " HP.\n";
        }
    }

    std::cout << "Musuh hidup: " << aliveCount << '\n';
    std::cout << "Musuh mati: " << deadCount << '\n';

    return 0;
}
