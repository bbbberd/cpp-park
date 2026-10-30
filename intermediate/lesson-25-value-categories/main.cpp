#include <iostream>
#include <utility>
#include <vector>

struct Payload {
    std::vector<int> values;
    explicit Payload(std::size_t count) : values(count, 42) {
        std::cout << "Membuat Payload\n";
    }

    Payload(const Payload &other) : values(other.values) {
        std::cout << "Copy constructor\n";
    }

    Payload(Payload &&other) noexcept : values(std::move(other.values)) {
        std::cout << "Move constructor\n";
    }
};

int main() {
    Payload original(1'000'000);

    std::cout << "\n-- Copy --\n";
    Payload copied = original;

    std::cout << "\n-- Move --\n";
    Payload moved = std::move(original);

    std::cout << "\nJumlah elemen:\n";
    std::cout << "Original: " << original.values.size() << '\n';
    std::cout << "Copied: " << copied.values.size() << '\n';
    std::cout << "Moved: " << moved.values.size() << '\n';

    return 0;
}
