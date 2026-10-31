#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> scores{80, 45, 90, 60, 45, 100};

    // 1. iterator ke elemen pertama
    auto it = scores.begin();

    std::cout << "First element: " << *it << '\n';

    // Pindah ke elemen berikutnya
    ++it;

    std::cout << "Second element: " << *it << '\n';

    // 2. Mencari element
    auto found = std::find(scores.begin(), scores.end(), 90);

    if (found != scores.end()) {
        std::cout << "Found: " << *found << '\n';
    }

    // 3. Menghitung elemen berikutnya kondisi.
    const auto passed =
        std::count_if(scores.begin(), scores.end(), [](int score) { return score >= 60; });

    std::cout << "Passed: " << passed << '\n';

    // 4. Mengurutkan elemen
    std::sort(scores.begin(), scores.end());

    std::cout << "Sorted: ";

    for (int score : scores) {
        std::cout << score << ' ';
    }

    std::cout << '\n';

    // 5.Menghapus semua elemen bernilai 45.
    scores.erase(std::remove(scores.begin(), scores.end(), 45), scores.end());

    std::cout << "After erase-remove: ";
    for (int score : scores) {
        std::cout << score << ' ';
    }
    std::cout << '\n';
    return 0;
}
