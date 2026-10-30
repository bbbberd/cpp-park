#include <array>
#include <iostream>

int main() {
    std::array<int, 4> equipmentSlots = {1, 2, 3, 4};
    std::cout << equipmentSlots[0] << '\n';
    std::cout << equipmentSlots[1] << '\n';

    std::cout << "Jumlah slot: " << equipmentSlots.size() << '\n';

    return 0;
}
