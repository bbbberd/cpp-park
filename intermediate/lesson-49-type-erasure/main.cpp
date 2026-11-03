#include <functional>
#include <iostream>

void attack() { std::cout << "Player attack!\n"; }

class jumpAction {
public:
    void operator()() const { std::cout << "Player jumps!\n"; }
};

int main() {
    std::function<void()> action;

    // function pointer
    action = attack;

    if (action) {
        action();
    }

    // functor
    action = jumpAction{};

    if (action) {
        action();
    }

    // lambda
    int damage = 100;
    action = [damage]() { std::cout << "Player deals " << damage << " damage!\n"; };

    if (action) {
        action();
    }

    // empty callback
    action = nullptr;

    if (!action) {
        std::cout << "No action assigned\n";
    }

    return 0;
}
