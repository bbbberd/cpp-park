#include <iostream>
#include <utility>
#include <vector>

class Inventory {
public:
    std::vector<int> items;

    Inventory() = default;

    // Copy constructor
    Inventory(const Inventory &other) : items(other.items) { std::cout << "Copy constructor\n"; }

    // Move constructor
    Inventory(Inventory &&other) noexcept : items(std::move(other.items)) {
        std::cout << "Move constructor\n";
    }

    // Copy assignment
    Inventory &operator=(const Inventory &other) {
        std::cout << "Copy assignment\n";

        if (this != &other) {
            items = other.items;
        }
        return *this;
    }

    // Move assignment
    Inventory &operator=(Inventory &&other) noexcept {
        std::cout << "Move assignment\n";
        if (this != &other) {
            items = std::move(other.items);
        }
        return *this;
    }
};

int main() {
    Inventory first;
    first.items = {10, 20, 30};

    // copy constructor
    Inventory second = first;

    // move constructor
    Inventory third = std::move(first);

    // copy assignment
    Inventory fourth;
    fourth = second;

    // move assignment
    Inventory fifth;
    fifth = std::move(fourth);

    std::cout << "\nSecond size: " << second.items.size() << '\n';
    std::cout << "Third size: " << third.items.size() << '\n';
    std::cout << "Fifth size: " << fifth.items.size() << '\n';
    return 0;
}
