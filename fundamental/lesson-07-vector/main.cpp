#include <iostream>
#include <memory>
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
    // 1. std::vector<int>

    std::vector<int> scores;

    scores.push_back(100);
    scores.push_back(250);
    scores.push_back(500);

    std::cout << "scores:\n";

    for (int score : scores) {
        std::cout << score << '\n';
    }

    std::cout << '\n';

    // ========================
    // 2.size() dan capacity()
    // ========================

    std::cout << "Size: " << scores.size() << '\n';
    std::cout << "Capacity: " << scores.capacity() << '\n';
    std::cout << '\n';

    //==================
    // 3.reserve()
    //==================

    std::vector<int> numbers;

    numbers.reserve(100);

    std::cout << "After reserve(100):\n";
    std::cout << "Size: " << numbers.size() << '\n';
    std::cout << "Capacity: " << numbers.capacity() << '\n';
    std::cout << '\n';

    // =======================
    // 4. vector berisi objek
    // =======================

    std::vector<Enemy> enemies;
    enemies.reserve(3);

    enemies.emplace_back(100);
    enemies.emplace_back(150);
    enemies.emplace_back(200);

    std::cout << "Enemies:\n";

    for (const Enemy &enemy : enemies) {
        std::cout << "Health: " << enemy.getHealth() << '\n';
    }
    std::cout << '\n';

    // ========================
    // 5. Modify object di dalam vector
    // ========================

    enemies[0].takeDamage(25);
    std::cout << "Enemy 0 after damage: " << enemies[0].getHealth() << '\n';
    std::cout << '\n';

    // ========================
    // 6. Unique_ptr
    // ========================

    auto player = std::make_unique<Enemy>(300);
    player->takeDamage(50);

    std::cout << "Unique_ptr object health: " << player->getHealth() << '\n';

    // ========================
    // 7.ownership
    // ========================
    auto anotherPlayer = std::move(player);
    std::cout << "Moved object health: " << anotherPlayer->getHealth() << '\n';

    // player tidak lagi menjadi owner
    // anotherPlayer yg memiliki objek tersebut.

    return 0;
}
