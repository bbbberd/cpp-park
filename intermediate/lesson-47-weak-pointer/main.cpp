#include <iostream>
#include <memory>

class Enemy;

class Player {
public:
    std::shared_ptr<Enemy> enemy;
    ~Player() { std::cout << "Player destroyed\n"; }
};

class Enemy {
public:
    std::weak_ptr<Player> player;

    void attack() {
        if (auto target = player.lock()) {
            std::cout << "Enemy attacks player\n";
        } else {
            std::cout << "Player no longer exists\n";
        }
    }

    ~Enemy() { std::cout << "Enemy destroyed\n"; }
};

int main() {
    auto player = std::make_shared<Player>();
    auto enemy = std::make_shared<Enemy>();

    player->enemy = enemy;
    enemy->player = player;

    enemy->attack();

    std::cout << "\nDestroyed player ownership...\n";

    player.reset();

    enemy->attack();

    return 0;
}
