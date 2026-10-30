#include <iostream>
#include <vector>

class Enemy {
  private:
    int health;

  public:
    Enemy(int health) : health(health) {}

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0)
            health = 0;
    }

    int getHealth() const { return health; }
};

int main() {
    std::vector<Enemy> enemies;

    // Kita tau kira2 ada 3 enemy.
    // reserve mencegah unnecessary reallocation
    enemies.reserve(3);

    enemies.emplace_back(100);
    enemies.emplace_back(150);
    enemies.emplace_back(200);

    // ===============
    // COPY
    // ===============

    std::cout << "Copy:\n";
    for (Enemy enemy : enemies) {
        std::cout << enemy.getHealth() << '\n';
    }

    std::cout << '\n';

    // ==============
    // Reference
    // ==============
    std::cout << "Reference:\n";

    for (Enemy &enemy : enemies) {
        enemy.takeDamage(10);
    }

    for (const Enemy &enemy : enemies) {
        std::cout << enemy.getHealth() << '\n';
    }

    std::cout << '\n';

    // ===============
    // Const Reference
    // ===============

    std::cout << "Const reference:\n";
    for (const Enemy &enemy : enemies) {
        std::cout << enemy.getHealth() << '\n';
    }
    std::cout << '\n';

    // =================
    // size dan capacity
    // =================

    std::cout << "Size: " << enemies.size() << '\n';

    std::cout << "Capacity: " << enemies.capacity() << '\n';

    return 0;
}
