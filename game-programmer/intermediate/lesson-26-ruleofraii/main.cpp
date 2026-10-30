#include <iostream>
#include <string>
#include <vector>

struct Inventory {
    std::string owner;
    std::vector<int> itemIDs;
};

int main() {
    Inventory original{"Player", {101, 205, 310}};

    Inventory copied = original;

    copied.itemIDs.push_back(999);

    std::cout << "Original: " << original.itemIDs.size() << '\n';
    std::cout << "Copied: " << copied.itemIDs.size() << '\n';
}
