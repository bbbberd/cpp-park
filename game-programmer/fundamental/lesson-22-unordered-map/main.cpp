#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::unordered_map<int, std::string> items{
        {101, "Potion"}, {205, "Sword"}, {310, "Shield"}};

    const int targetID = 205;

    auto item = items.find(targetID);

    if (item != items.end()) {
        std::cout << "Item ditemukan: " << item->second << '\n';
    } else {
        std::cout << "Item tidak ditemukan.\n";
    }
    return 0;
}
