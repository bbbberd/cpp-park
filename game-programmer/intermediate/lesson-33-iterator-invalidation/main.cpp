#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> health{100, 0, 150, 0, 200};

    // Contoh iterator invalid, nilai it dihapus tapi malah ++it ditambah padahal ga ada.
    /*
     * for (auto it = health.begin(); it != health.end(); ++it)
     *  {
     *      if (*it == 0) {
     *          health.erase(it);
     *      }
     *  }
     */

    // Maka gunakan dibawah ini .erase()
    /*
     * auto it = health.begin();
     *  while (it != health.end()) {
     *      if (*it == 0) {
     *          it = health.erase(it);
     *      } else {
     *          ++it;
     *      }
     *  }
     *
     * for (int hp : health) {
     *  std::cout << hp << ' ';
     *  }
     *
     */

    // atau ini yg lebih ringkas std::remove
    health.erase(std::remove(health.begin(), health.end(), 0), health.end());

    for (int hp : health) {
        std::cout << hp << ' ';
    }

    std::cout << '\n';
}
