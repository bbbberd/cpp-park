#include <charconv>
#include <iostream>
#include <string>
#include <string_view>
#include <system_error>

// teks ke angka std::from_chars
bool parseInt(std::string_view text, int &result) {
    const char *first = text.data();
    const char *last = first + text.size();

    auto [ptr, ec] = std::from_chars(first, last, result);

    return ec == std::errc{} && ptr == last;
}

int main() {
    std::string playerName = "Wander";
    int hp{};
    float stamina = 75.5f;

    std::string input;

    std::cout << "Player: " << playerName << '\n';

    while (true) {
        std::cout << "Masukkan HP (0-100): ";

        if (!std::getline(std::cin, input)) {
            std::cout << "\nInput berakhir atau gagal.\n";
            return 1;
        }

        if (!parseInt(input, hp)) {
            std::cout << "Input harus berupa integer.\n";
            continue;
        }

        if (hp < 0 || hp > 100) {
            std::cout << "HP harus antara 0 dan 100.\n";
            continue;
        }

        break;
    }

    std::cout << "HP diterima: " << hp << '\n';

    std::cout << "HP: " << hp << '\n';
    std::cout << "Stamina: " << stamina << '\n';

    int age{};
    std::string nama;

    std::cout << "Umur: ";
    std::cin >> age;
    std::cin.ignore(1, '\n');

    std::cout << "Nama: ";
    std::getline(std::cin, nama);

    std::cout << "Nama: " << nama << '\n';

    return 0;
}
