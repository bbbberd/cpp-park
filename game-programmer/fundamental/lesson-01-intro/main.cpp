#include <iostream>

int main() {

    float stamina = 100.0f;
    const float sprintCostPerSecond = 20.0f;
    const float deltaTime = 0.5f;

    std::cout << "Starting stamina: " << stamina << "\n";

    for (int frame = 0; frame < 10; ++frame) {
    
        stamina -= sprintCostPerSecond * deltaTime;
        if (stamina < 0.0f) {
            stamina = 0.0f;
        }
        
        std::cout << "Frame " << frame << " | Stamina: " << stamina << "\n";
  }
  return 0;
}
