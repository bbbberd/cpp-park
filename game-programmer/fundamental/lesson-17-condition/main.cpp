#include <iostream>

int main() {
    int playerHP = 0;
    int stamina = 25;
    bool isNearWall = true;

    if (playerHP <= 0) {
        std::cout << "Pemain mati.\n";
    } else if (isNearWall && stamina >= 20) {
        std::cout << "Pemain bisa memanjat.\n";
    } else if (isNearWall && stamina < 20) {
        std::cout << "Pemain kelelahan.\n";
    } else {
        std::cout << "Tidak ada aksi khusus.\n";
    }

    int weaponType = 2;

    switch (weaponType) {
    case 1:
        std::cout << "pedang\n";
        break;
    case 2:
        std::cout << "Tombak\n";
        break;
    case 3:
        std::cout << "Busur\n";
        break;
    default:
        std::cout << "Senjata tidak dikenal\n";
        break;
    }

    return 0;
}
