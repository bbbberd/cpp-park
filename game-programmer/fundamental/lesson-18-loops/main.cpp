#include <array>
#include <iostream>

int main() {

    // 1. for loop
    for (int i = 1; i <= 5; i++) {
        std::cout << i;
    }

    std::cout << '\n';

    // 2. while loop
    int stamina = 100;

    while (stamina > 0) {
        std::cout << "Stamina: " << stamina << '\n';
        stamina -= 25;
    }

    std::cout << "Stamina habis.\n";

    // 3. do-while
    int attempts = 0;

    do {
        std::cout << "Memeriksa status pemain...\n";
        ++attempts;
    } while (attempts < 1);

    std::cout << "Pemeriksaan selesai.\n";

    // 4. range-based loop
    std::array<int, 4> enemyHP = {100, 75, 50, 25};

    for (int hp : enemyHP) {
        std::cout << "Enemey HP: " << hp << '\n';
    }

    // 5. break vs continue
    std::array<int, 4> enemyHP2 = {100, 75, 0, 25};

    // break
    for (int hp : enemyHP2) {
        if (hp <= 0) {
            std::cout << "Musuh mati ditemukan.\n";
            break;
        }

        std::cout << "Musuh masih hidup: " << hp << '\n';
    }

    // continue
    for (int hp : enemyHP2) {
        if (hp <= 0) {
            continue;
        }
        std::cout << "musuh aktif, HP: " << hp << '\n';
    }

    return 0;
}
