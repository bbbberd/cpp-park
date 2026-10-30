#include <algorithm>
#include <array>
#include <iostream>

int main() {
    const std::array<int, 6> enemyHP = {100, 0, 45, 15, 0, 80};
    const auto isAlive = [](int hp) { return hp > 0; };
    const auto isCritical = [](int hp) { return hp > 0 && hp < 30; };

    // count_if
    const auto aliveCount =
        std::count_if(enemyHP.begin(), enemyHP.end(), isAlive);
    const auto deadCount = std::count_if(enemyHP.begin(), enemyHP.end(),
                                         [](int hp) { return hp <= 0; });

    // any_of
    const bool hasCriticalEnemy =
        std::any_of(enemyHP.begin(), enemyHP.end(), isCritical);

    // find_if
    const auto criticalit =
        std::find_if(enemyHP.begin(), enemyHP.end(), isCritical);

    std::cout << "Musuh hidup: " << aliveCount << '\n';
    std::cout << "Musuh mati: " << deadCount << '\n';

    if (hasCriticalEnemy) {
        std::cout << "Ada musuh dalam kondisi kritis.\n";
        std::cout << "HP musuh kritis pertama: " << *criticalit << '\n';
    } else {
        std::cout << "Tidak ada musuh dalam kondisi kritis.\n";
    }

    /*
     * std::find = Linier mencari nilai utk array/vector
     * std::find_if = Mencari berdasar kondisi, berhenti jika cocok
     * std::count_if = Menghitung kecocokan, seluruhnya
     * std::any_of = Memeriksa ada kecocokan, berhenti jika iya
     * std::all_of = Memeriksa apakah semua cocok
     * std::transform = Mengubah elemen tergantung alokasi dan rentang
     */

    return 0;
}
