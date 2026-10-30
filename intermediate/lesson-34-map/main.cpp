#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

struct Enemy {
    std::string name;
    int health;
};

int main() {

    // praktik 1 unordered_map
    // std::unordered_map<tipe key, tipe value> enemies;
    std::unordered_map<int, Enemy> enemies{
        {101, {"Goblin", 50}}, {250, {"Dragon", 300}}, {507, {"Colossus", 120}}};

    const int targetId = 507;

    auto it = enemies.find(targetId);

    if (it != enemies.end()) {
        Enemy &enemy = it->second;
        std::cout << "Target: " << enemy.name << '\n';
        std::cout << "HP: " << enemy.health << '\n';
        enemy.health -= 20;
        std::cout << "HP after damage: " << enemy.health << '\n';

    } else {
        std::cout << "Enemy not found.\n";
    }

    // praktik 2 map
    // perbedaan map hanyalah di penyimpanan yg urut berdasarkan key
    // sedangkan unordered_map tidak urut dan menggunakan hash table
    //
    // map = O(log n)
    // unordered_map = O(1) rata-rata
    //
    // Apa artinya O(log n) dan O(1)?
    // - O(log n): pencarian bertambah relatif lambat ketika jumlah elemen meningkat.
    // - O(1) rata-rata: waktu pencarian biasanya relatif konstan terhadap jumlah elemen.
    // - O(n) terburuk: dalam kondisi tertentu, pencarian dapat memeriksa banyak elemen.
    //
    // meskipun unordered_map memiliki pencarian rata-rata O(1),
    // bukan berarti ia selalu lebih cepat daripada map dalam semua situasi.

    std::map<int, Enemy> mapEnemies{
        {101, {"Goblin", 50}}, {205, {"Dragon", 300}}, {507, {"Colossus", 120}}};

    // Kesimpulan
    std::cout << "\nUNORDERED MAP: ALL ENEMIES\n";
    for (const auto &[id, enemy] : enemies) {
        std::cout << id << ": " << enemy.name << " (HP " << enemy.health << ")\n";
    }

    std::cout << "\nMAP: ALL ENEMIES\n";
    for (const auto &[id, enemy] : mapEnemies) {
        std::cout << id << ": " << enemy.name << " (HP " << enemy.health << ")\n";
    }
}
