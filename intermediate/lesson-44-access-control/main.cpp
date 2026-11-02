#include <iostream>

// simple data structure
struct Vector2 {
    float x;
    float y;
};

// class with encapsulation
class Player {
private:
    int health = 100;
    int maxHealth = 100;

public:
    void takeDamage(int damage) {
        if (damage <= 0) {
            return;
        }

        health -= damage;

        if (health < 0) {
            health = 0;
        }
    }

    void heal(int amount) {
        if (amount <= 0) {
            return;
        }

        health += amount;

        if (health > maxHealth) {
            health = maxHealth;
        }
    }

    int getHealth() const { return health; }
};

int main() {
    Vector2 position{10.0f, 20.0f};
    Player player;
    player.takeDamage(30);
    player.heal(10);

    std::cout << "Position: " << position.x << ", " << position.y << '\n';

    std::cout << "Player health: " << player.getHealth() << '\n';

    return 0;
}
