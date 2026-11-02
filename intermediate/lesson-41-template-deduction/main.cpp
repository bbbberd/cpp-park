#include <iostream>
#include <string>

// Satu template parameter
template <typename T> T addSameType(T a, T b) { return a + b; }

// Dua template parameter
template <typename T, typename U> auto addDifferentTypes(T a, U b) { return a + b; }

// Dua tipe berbeda dalam satu fungsi
template <typename T, typename U> void printPair(T first, U second) {
    std::cout << first << " - " << second << '\n';
}

int main() {
    // Compiler menyimpulkan T = int
    std::cout << addSameType(10, 20) << '\n';

    // Compiler menyimpulkan T = double
    std::cout << addSameType(2.5, 3.5) << '\n';

    // Menentukan T secara eksplisit
    std::cout << addSameType<double>(10, 2.5) << '\n';

    // Compiler menyimpulkan T = int, U = double
    std::cout << addDifferentTypes(10, 2.5) << '\n';

    // T = int, U = string
    printPair(100, std::string{"Player"});

    // T = double, U = int
    printPair(3.14, 42);

    return 0;
}
