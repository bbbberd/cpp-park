#include <iostream>
#include <memory>

class Player {
  private:
    int health;

  public:
    Player(int health) : health(health) {}

    void takeDamage(int damage) { health -= damage; }

    int getHealth() const { return health; }
};

int main() {
    Player a(100);

    // Copy
    Player b = a;

    // Alias/Reference
    Player &ref = a;

    // Pointer
    Player *ptr = &a;

    b.takeDamage(10);
    ref.takeDamage(20);
    ptr->takeDamage(30);

    std::cout << "a: " << a.getHealth() << '\n';
    std::cout << "b: " << b.getHealth() << '\n';
}
