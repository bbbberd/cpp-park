#include <iostream>

// 1. fungsi template
template <typename T> T add(T a, T b) { return a + b; }

template <typename T> T maxValue(T a, T b) { return (a > b) ? a : b; }

// 2. Class template
template <typename T> class Storage {
private:
    T value;

public:
    Storage(T initialValue) : value(initialValue) {}
    T get() const { return value; }
    void set(T newValue) { value = newValue; }
};

int main() {
    // fungsi template
    std::cout << "FUNCTION TEMPLATE \n";
    std::cout << add(10, 20) << '\n';
    std::cout << add(1.5, 2.5) << '\n';

    std::cout << "Max: " << maxValue(10, 50) << '\n';
    std::cout << "Max: " << maxValue(4.5, 2.5) << '\n';

    // class template
    std::cout << "\nCLASS TEMPLATE \n";
    Storage<int> health(100);
    Storage<float> speed(5.5f);

    std::cout << "Health: " << health.get() << '\n';
    std::cout << "Speed: " << speed.get() << '\n';

    health.set(75);

    std::cout << "Updated health: " << health.get() << '\n';

    return 0;
}
