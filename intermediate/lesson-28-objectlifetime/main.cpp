#include <iostream>
#include <vector>

int main() {
    std::vector<int> values;
    values.reserve(2);

    values.push_back(10);
    values.push_back(20);

    int *pointer = &values[0];

    std::cout << "Sebelum penambahan: " << *pointer << '\n';

    // jangan dereference pointer.
    // push_back dapat menyebabkan reallocation.

    pointer = nullptr;

    std::cout << "Jumlah elemen: " << values.size() << '\n';
}
