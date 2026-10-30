#include <iostream>
#include <set>
#include <unordered_set>

int main() {
    std::set<int> deadEnemies{101, 205, 101, 507};

    std::cout << "SET\n";

    for (int id : deadEnemies) {
        std::cout << id << ' ';
    }

    std::cout << '\n';

    if (deadEnemies.contains(205)) {
        std::cout << "Enemy 205 is registered.\n";
    }

    // insert() tidak membuat duplikat.
    auto [it, inserted] = deadEnemies.insert(205);
    std::cout << "Inserted 205 again: " << std::boolalpha << inserted << '\n';

    deadEnemies.erase(205);
    std::cout << "After erase:\n";
    for (int id : deadEnemies) {
        std::cout << id << ' ';
    }

    std::cout << "\n\n";

    std::unordered_set<int> unorderedDeadEnemies{101, 205, 101, 507};

    std::cout << "UNORDERED SET\n";
    if (unorderedDeadEnemies.contains(507)) {
        std::cout << "Enemy 507 is registered\n";
    }

    unorderedDeadEnemies.insert(900);
    unorderedDeadEnemies.erase(205);

    std::cout << "Remaining IDs:\n";

    for (int id : unorderedDeadEnemies) {
        std::cout << id << ' ';
    }
    std::cout << '\n';
}
