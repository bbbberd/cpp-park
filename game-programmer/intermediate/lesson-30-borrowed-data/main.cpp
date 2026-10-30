#include <iostream>
#include <string>
#include <string_view>

void printCommand(std::string_view command) {
    std::cout << "Command: " << command << '\n';
    std::cout << "Length: " << command.size() << '\n';
}

int main() {
    std::string input = "spawn_colossus";

    printCommand(input);
    printCommand("quit");

    std::string_view prefix = input;
    prefix.remove_prefix(6);

    std::cout << "After prefix: " << prefix << '\n';
}
