#include <iostream>
#include <string>

class Weapon {
private:
    std::string name;

public:
    Weapon(const std::string &weaponName) : name(weaponName) { std::cout << name << " created\n"; }

    ~Weapon() { std::cout << name << " destroyed\n"; }
};

class Player {
private:
    int health;
    Weapon weapon;

public:
    Player(int initialHealth, const std::string &weaponName)
        : health(initialHealth), weapon(weaponName) {
        std::cout << "Player created\n";
    }
    ~Player() { std::cout << "Player destroyed\n"; }
    void showStatus() const { std::cout << "Health: " << health << '\n'; }
};

int main() {
    std::cout << "Game started\n";
    {
        Player player(100, "Sword");
        player.showStatus();
        std::cout << "Player is active\n";
    }

    std::cout << "Game continues\n";
    return 0;
}
