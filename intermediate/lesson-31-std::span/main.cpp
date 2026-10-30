#include <iostream>
#include <span>
#include <vector>

void damageEnemies(std::span<int> health, int damage) {
    for (int &hp : health) {
        hp -= damage;

        if (hp < 0) {
            hp = 0;
        }
    }
}

int totalHealth(const std::vector<int> &health) {
    int total = 0;
    for (int hp : health) {
        total += hp;
    }
    return total;
}

int main() {
    std::vector<int> enemies{100, 150, 200};
    damageEnemies(enemies, 50);

    for (int hp : enemies) {
        std::cout << hp << ' ';
    }

    std::cout << '\n';
}
