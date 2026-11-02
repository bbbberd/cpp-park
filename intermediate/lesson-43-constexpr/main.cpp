#include <iostream>

// compile time constant
constexpr int max_player = 4;

// constexpr function
constexpr int square(int value) { return value * value; }

// Compile time conversion
constexpr float degreesToRadians(float degrees) { return degrees * 3.14159265f / 180.0f; }

// must be evaluated at compile time
consteval int calculateCapacity(int slots) { return slots * 8; }

int main() {
    // compile time computation
    constexpr int result = square(5);
    constexpr float rotation = degreesToRadians(90.0f);
    constexpr int inventoryCapacity = calculateCapacity(4);

    // runtime computation using constexpr function
    int playerLevel = 10;
    int levelSquared = square(playerLevel);

    std::cout << "Max player: " << max_player << '\n';
    std::cout << "Square: " << result << '\n';
    std::cout << "90 degress in radians: " << rotation << '\n';
    std::cout << "Inventory capacity: " << inventoryCapacity << '\n';
    std::cout << "Player level squared: " << levelSquared << '\n';
}
