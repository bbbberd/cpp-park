#include <iostream>

class Player {

  private:
    int health;
    int maxHealth;
    float speed;

  public:
    Player(int maxHealth, float speed)
        : health(maxHealth), maxHealth(maxHealth), speed(speed) {}

    void takeDamage(int damage) {

        health -= damage;
        if (health < 0) {
            health = 0;
        }
    }

    void Heal(int amount) {

        health += amount;
        if (health > maxHealth) {
            health = maxHealth;
        }
    }

    bool isDead() const { return health == 0; }

    int getHealth() const { return health; }
};

int main() {
    Player player(100, 600.0f);

    player.takeDamage(25);
    std::cout << "Health: " << player.getHealth() << '\n';

    player.Heal(10);

    std::cout << "Health: " << player.getHealth() << '\n';

    if (player.isDead()) {
        std::cout << "Player died.\n";
    } else {
        std::cout << "Playerr alived.\n";
    }
}
