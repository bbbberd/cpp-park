#include <concepts>
#include <iostream>

// custom concepts
// T must be an integer or floating point
template <typename T>
concept Number = std::integral<T> || std::floating_point<T>;

// Only accepts integral types.
template <std::integral T> T multiply(T a, T b) { return a * b; }

// only accepts types that satisfy number.
template <Number T> T add(T a, T b) { return a + b; }

// custom concept based on an operation
template <typename T>
concept Addable = requires(T a, T b) { a + b; };

// only accepts types where a + b is valid
template <Addable T> T combine(T a, T b) { return a + b; }

int main() {
    std::cout << "Multiply: " << multiply(5, 10) << '\n';

    std::cout << "Add integers: " << add(10, 20) << '\n';

    std::cout << "Add floating_point: " << add(1.5, 2.5) << '\n';

    std::cout << "Combine integers: " << combine(100, 200) << '\n';

    return 0;
}
