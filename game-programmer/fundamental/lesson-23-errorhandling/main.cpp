#include <iostream>
#include <optional>
#include <stdexcept>

int divide(int numerator, int denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator tidak boleh nol.");
    }
    /*
     * Fungsi divide() mendeteksi denominator nol dan
     * melempar exception.
     * Fungsi tidak melanjutkan ke operasi pembagian.
     */
    return numerator / denominator;
}

std::optional<int> findPlayerLevel(int playerID) {
    if (playerID == 42) {
        return 15;
    }

    return std::nullopt;
}

int main() {
    try {
        const int result = divide(10, 0);
        std::cout << "Hasil: " << result << '\n';

        /*
         * Kode di dalam blok ini adalah kode yang
         * mungkin melempar exception dan ingin kita tangani.
         */
    } catch (const std::invalid_argument &error) {
        std::cerr << "Operasi gagal: " << error.what() << '\n';
        /*
         * Exception dengan tipe yang cocok ditangkap di sini.
         * error.what() menyediakan pesan penjelasan.
         */
    }

    std::cout << "Program tetap berjalan.\n";

    // perbandingan dengan optional
    const auto level = findPlayerLevel(99);

    if (level.has_value()) {
        std::cout << "Level: " << *level << '\n';
    } else {
        std::cout << "Pemain tidak ditemukan.\n";
    }

    /*
     * return value cocok untuk operasi dengan status sederhana,
     * tapi pemanggil harus memeriksa hasilnya
     *
     * std::optional<T> penting utk nilai yg mungkin tersedia,
     * namun tidak menjelaskan penyebab kegagalan
     *
     * sedangkan stdexcept untuk kegagalan yg perlu di teruskan
     * ke lapisan pemanggil, dan perlu memahami alur kontrol exception
     * */
    return 0;
}
