#pragma once

class Player {
  private:
    int health;

  public:
    Player(int health);
    void takeDamage(int damage);
    int getHealth() const;
};
