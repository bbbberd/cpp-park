#include <iostream>

enum class playerState { Idle, Running, Attacking, Dead };

int main() {
    playerState state = playerState::Running;

    if (state == playerState::Running) {
        std::cout << "Player is running\n";
    }

    state = playerState::Attacking;

    if (state == playerState::Attacking) {
        std::cout << "Player is attacking\n";
    }

    return 0;
}
