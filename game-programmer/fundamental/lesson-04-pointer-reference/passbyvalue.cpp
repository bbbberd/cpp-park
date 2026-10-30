#include <iostream>

void takeDamage(int &health, int damage) {
    health -= damage;

    if (health < 0) {
        health = 0;
    }
}

int main() {
    int health = 100;
    takeDamage(health, 25);
    takeDamage(health, 30);
    std::cout << health << '\n';
}
