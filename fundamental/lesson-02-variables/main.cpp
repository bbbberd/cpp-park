#include <iostream>
#include <string>

int main(){

    std::string playerName = "Player";
    
    int health = 100;
    const int maxHealth = 100;

    float stamina = 100.0f;
    const float maxStamina = 100.0f;

    float movementSpeed = 600.0f;
    bool isSprinting = false;

    std::cout << "Player: " << playerName << "\n";
    std::cout << "Health: " << health << "/" << maxHealth << "\n";
    std::cout << "Stamina: " << stamina << "/" << maxStamina << "\n";
    std::cout << "Speed: " << movementSpeed << "\n";
    std::cout << "Sprinting: " << isSprinting << "\n";

    return 0;
}

