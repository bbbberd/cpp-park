#include "Player.h"

Player::Player(int health) : health(health) {}

void Player::takeDamage(int damage) {
    health -= damage;
    if (health < 0)
        health = 0;
}

int Player::getHealth() const { return health; }
