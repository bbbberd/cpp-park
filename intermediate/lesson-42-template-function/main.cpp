#include <iostream>
#include <string>

// Function overloading
void print(int value) { std::cout << "Integer: " << value << '\n'; }

void print(double value) { std::cout << "Double: " << value << '\n'; }

// Function template
template <typename T> void display(T value) { std::cout << "Generic: " << value << '\n'; }

// Template + overload
template <typename T> void process(T value) {
    std::cout << "Generic processing: " << value << '\n';
}

void process(int value) { std::cout << "Special integer processing: " << value << '\n'; }

int main() {
    // overloading
    print(100);
    print(3.14);

    // Template
    display(42);
    display(3.14);
    display(std::string{"Player"});

    // Template + overloading
    process(100);
    process(3.14);
    return 0;
}
