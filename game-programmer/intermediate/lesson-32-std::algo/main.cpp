#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Enemy {
    std::string name;
    int health;
};

int main() {
    std::vector<Enemy> enemies{{"Goblin", 50}, {"Colossus", 300}, {"Skeleton", 0}, {"Dragon", 120}};

    const auto aliveCount = std::count_if(enemies.begin(), enemies.end(),
                                          [](const Enemy &enemy) { return enemy.health > 0; });

    const auto weakest =
        std::min_element(enemies.begin(), enemies.end(),
                         [](const Enemy &a, const Enemy &b) { return a.health < b.health; });

    std::cout << "Living enemies: " << aliveCount << '\n';

    if (weakest != enemies.end()) {
        std::cout << "Lowest HP: " << weakest->name << " (" << weakest->health << ")\n";
    }
}

/*
 * Mengenai lambda : merupakan fungsi tanpa nama yang kita tulis langsung di tempat, ga harus untuk
 * STL.
 *
 * [](int hp) { return hp > 100; }
 * │ │        │ │                │
 * │ │        │ └─ Isi fungsi    └─ Akhir fungsi
 * │ │        └─ Awal isi fungsi
 * │ └─ Parameter: menerima hp
 * └─ Penanda lambda
 *
 */
