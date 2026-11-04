#include <any>
#include <iostream>
#include <string>

int main() {
    std::any value;

    // store int
    value = 100;

    std::cout << "Type: int\n";
    std::cout << "Value: " << std::any_cast<int>(value) << '\n';

    // replace it with a string
    value = std::string("Hello, C++");

    std::cout << "\nType: string\n";
    std::cout << "Value: " << std::any_cast<std::string>(value) << '\n';

    // safe pointer style access
    if (const auto *text = std::any_cast<std::string>(&value)) {
        std::cout << "\nSafe access: " << *text << '\n';
    }

    // check whether value contains something
    if (value.has_value()) {
        std::cout << "\nValue exists\n";
    }

    std::cout << "Stored type: " << value.type().name() << '\n';

    return 0;
}
