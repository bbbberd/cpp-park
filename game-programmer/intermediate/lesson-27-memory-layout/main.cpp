#include <cstddef>
#include <iostream>

struct Example {
    int b;
    char c;
    char a;
};

int main() {
    std::cout << "sizeof(char): " << sizeof(char) << '\n';
    std::cout << "sizeof(int): " << sizeof(int) << '\n';
    std::cout << "sizeof(Example): " << sizeof(Example) << '\n';

    std::cout << "Offset a: " << offsetof(Example, a) << '\n';
    std::cout << "Offset b: " << offsetof(Example, b) << '\n';
    std::cout << "Offset c: " << offsetof(Example, c) << '\n';
}
