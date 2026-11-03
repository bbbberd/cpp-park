#include <iostream>
#include <utility>

// variadic template with fold expression
template <typename... Args> void log(Args &&...args) {
    std::cout << "[LOG] ";
    (std::cout << ... << std::forward<Args>(args));
    std::cout << '\n';
}

// variadic template for counting Arguments
template <typename... Args> void showArgumentCount(Args &&...args) {
    std::cout << "Argument count: " << sizeof...(args) << '\n';
}

int main() {
    log("Player HP: ", 100, " Position: ", 25.5f);

    showArgumentCount(10, 20, 30);
    showArgumentCount("Attack", 50.0f);

    return 0;
}
