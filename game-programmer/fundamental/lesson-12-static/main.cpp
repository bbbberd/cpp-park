#include <iostream>

void update() {
    int normal = 0;
    static int persistent = 0;

    ++normal;
    ++persistent;

    std::cout << normal << " | " << persistent << '\n';
}

class Enemy {
  private:
    static int count;

  public:
    Enemy() { ++count; }
    static int getCount() { return count; }
};

int Enemy::count = 0;

int main() {
    update();
    update();
    update();

    Enemy a;
    Enemy b;
    Enemy c;

    std::cout << Enemy::getCount() << '\n';
}
