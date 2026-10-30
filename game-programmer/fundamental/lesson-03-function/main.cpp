#include <iostream>

int applyDamage(int currentHealth, int damage) {
    int newHealth = currentHealth - damage;
    if (newHealth < 0) {
        newHealth = 0;
    }

    return newHealth;
}

bool isDead(int health) { return health <= 0; }

int main() {

    int health = 100;

    health = applyDamage(health, 25);
    std::cout << "health: " << health << "\n";

    health = applyDamage(health, 80);
    std::cout << "health: " << health << "\n";

    if (isDead(health)) {
        std::cout << "Player is dead.\n";
    }

    return 0;
}
