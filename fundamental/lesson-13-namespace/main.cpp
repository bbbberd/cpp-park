#include <iostream>

namespace playerSystem {
void print() { std::cout << "Player status\n"; }
} // namespace playerSystem

namespace cameraSystem {
void print() { std::cout << "Camera status\n"; }
} // namespace cameraSystem

int main() {
    playerSystem::print();
    cameraSystem::print();
    return 0;
}
