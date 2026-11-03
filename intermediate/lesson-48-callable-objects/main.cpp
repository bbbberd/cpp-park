#include <iostream>

// ordinary functions
void attack() { std::cout << "Player attacks\n"; }

void jump() { std::cout << "Player jumps\n"; }

// function pointer callback
void executeAction(void (*action)()) { action(); }

// function object
class damageAction {
private:
    int damage;

public:
    explicit damageAction(int value) : damage(value) {}

    void operator()() const { std::cout << "damage: " << damage << '\n'; }
};

int main() {
    // function pointer
    void (*action)() = attack;
    action();

    // callback
    executeAction(jump);

    // functor
    damageAction heavyAttack(100);
    heavyAttack();

    // lambda
    int damage = 50;

    auto lightAttack = [damage]() { std::cout << "Light attack damage: " << damage << '\n'; };

    lightAttack();

    return 0;
}
