#include <charconv>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>
#include <system_error>
#include <unordered_map>

struct Item {
    std::string name;
    int quantity;
};

using Inventory = std::unordered_map<int, Item>;

std::optional<int> parseInteger(std::string_view text) {
    int value{};
    const auto result =
        std::from_chars(text.data(), text.data() + text.size(), value);

    if (result.ec != std::errc{} || result.ptr != text.data() + text.size()) {
        return std::nullopt;
    }

    return value;
}

bool addItem(Inventory &inventory, int id, std::string name, int quantity) {
    if (id <= 0 || name.empty() || quantity <= 0) {
        return false;
    }

    const auto [iterator, inserted] =
        inventory.try_emplace(id, Item{std::move(name), quantity});
    (void)iterator;
    return inserted;
}

const Item *findItem(const Inventory &inventory, int id) {
    const auto iterator = inventory.find(id);
    if (iterator == inventory.end()) {
        return nullptr;
    }
    return &iterator->second;
}

void printItems(const Inventory &inventory) {
    if (inventory.empty()) {
        std::cout << "Inventory kosong.\n";
        return;
    }

    for (const auto &[id, item] : inventory) {
        std::cout << "ID: " << id << " | Nama: " << item.name
                  << " | Jumlah: " << item.quantity << '\n';
    }
}

int main() {
    Inventory inventory{{101, {"Potion", 5}},
                        {205, {"Iron Sword", 1}},
                        {310, {"Wooden Shield", 1}}};

    while (true) {
        std::cout << "\n=== RPG Inventory ===\n"
                  << "1. Tampilkan item\n"
                  << "2. Cari item\n"
                  << "3. Tambah item\n"
                  << "0. Keluar\n"
                  << "Pilihan: ";

        std::string input;

        if (!std::getline(std::cin, input)) {
            break;
        }

        const auto choice = parseInteger(input);

        if (!choice) {
            std::cout << "Input harus berupa angka.\n";
            continue;
        }

        switch (*choice) {
        case 1:
            printItems(inventory);
            break;
        case 2: {
            std::cout << "ID item: ";
            if (!std::getline(std::cin, input)) {
                return 0;
            }

            const auto id = parseInteger(input);

            if (!id || *id <= 0) {
                std::cout << "ID tidak valid.\n";
                break;
            }

            const Item *item = findItem(inventory, *id);

            if (item == nullptr) {
                std::cout << "Item tidak ditemukan.\n";
            } else {
                std::cout << item->name << " | Jumlah: " << item->quantity
                          << '\n';
            }
            break;
        }
        case 3: {
            std::string name;
            int id{};
            int quantity{};

            std::cout << "ID baru: ";

            if (!std::getline(std::cin, input)) {
                return 0;
            }

            const auto parsedID = parseInteger(input);

            if (!parsedID || *parsedID <= 0) {
                std::cout << "ID tidak valid.\n";
                break;
            }

            id = *parsedID;

            std::cout << "Nama item: ";

            if (!std::getline(std::cin, name)) {
                return 0;
            }

            std::cout << "Jumlah: ";
            if (!std::getline(std::cin, input)) {
                return 0;
            }

            const auto parsedQuantity = parseInteger(input);

            if (!parsedQuantity || *parsedQuantity <= 0) {
                std::cout << "Jumlah tidak valid.\n";
                break;
            }

            quantity = *parsedQuantity;

            if (addItem(inventory, id, std::move(name), quantity)) {
                std::cout << "Item berhasil ditambahkan.\n";
            } else {
                std::cout << "Gagal: data tidak valid atau ID sudah ada.\n";
            }
            break;
        }
        case 0:
            std::cout << "Program selesai.\n";
            return 0;

        default:
            std::cout << "Pilihan tidak tersedia.\n";
            break;
        }
    }
    return 0;
}
