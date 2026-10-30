#include <array>
#include <charconv>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>
#include <system_error>

struct Enemy {
    int id;
    int hp;
};

std::optional<Enemy> findEnemy(const std::array<Enemy, 3> &enemies,
                               int targetId) {
    for (const Enemy &enemy : enemies) {
        if (enemy.id == targetId) {
            return enemy;
        }
    }
    return std::nullopt;
}

// Parsing example
std::optional<int> parseInt(std::string_view text) {
    int result{};

    const char *first = text.data();
    const char *last = first + text.size();

    auto [ptr, ec] = std::from_chars(first, last, result);

    if (ec != std::errc{} || ptr != last) {
        return std::nullopt;
    }

    return result;
}

int main() {
    const std::array<Enemy, 3> enemies = {{{101, 100}, {102, 75}, {103, 0}}};

    std::optional<Enemy> result = findEnemy(enemies, 102);

    if (result) {
        std::cout << "Enemy ditemukan, HP: " << result->hp << '\n';
    } else {
        std::cout << "Enemy tidak ditemukan.\n";
    }

    // parseInt
    std::string input;

    std::cout << "Masukkan HP: ";

    if (!std::getline(std::cin, input)) {
        std::cout << "Input gagal.\n";
        return 1;
    }

    std::optional<int> hp = parseInt(input);

    if (!hp) {
        std::cout << "Integer tidak valid.\n";
        return 1;
    }

    std::cout << "HP: " << *hp << '\n';

    return 0;
}
