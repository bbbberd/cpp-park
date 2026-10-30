#include <iostream>

class Player {
  private:
    int health;

  public:
    Player(int health) : health(health) {}

    int getHealth() const { return health; }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0)
            health = 0;
    }
};

void printHealth(const Player &player) {
    std::cout << "Health: " << player.getHealth() << '\n';
}

int main() {
    Player player(100);
    printHealth(player);
    player.takeDamage(30);
    printHealth(player);
    return 0;
}
