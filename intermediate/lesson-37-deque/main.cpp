#include <deque>
#include <iostream>

int main() {
    std::deque<int> readings;

    // Data awal
    readings.push_back(100);
    readings.push_back(110);
    readings.push_back(120);

    // tambah data di depan dan belakang
    readings.push_front(90);
    readings.push_back(130);

    std::cout << "Readings: ";

    for (int value : readings) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    // Baca kedua ujung
    if (!readings.empty()) {
        std::cout << "Oldest: " << readings.front() << '\n';
        std::cout << "Newest: " << readings.back() << '\n';
    }

    // Buang satu data terlama
    if (!readings.empty()) {
        readings.pop_front();
    }

    // Buang satu data terbaru
    if (!readings.empty()) {
        readings.pop_back();
    }

    std::cout << "After removing both ends: ";
    for (int value : readings) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    // Akses berdasarkan indeks
    if (!readings.empty()) {
        std::cout << "First element: " << readings[0] << '\n';
    }

    return 0;
}
