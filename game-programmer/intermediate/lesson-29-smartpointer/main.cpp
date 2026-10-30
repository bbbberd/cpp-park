#include <iostream>
#include <memory>
#include <string>

// unique_pointer
struct Entity {
    std::string name;

    explicit Entity(std::string entityName) : name(std::move(entityName)) {
        std::cout << name << " dibuat.\n";
    }

    ~Entity() { std::cout << name << " dihancurkan.\n"; }

    void update() const { std::cout << name << " sedang di-update.\n"; }
};

// shared_pointer
struct Texture {
    std::string name;

    explicit Texture(std::string textureName) : name(std::move(textureName)) {
        std::cout << "Load: " << name << '\n';
    }

    ~Texture() { std::cout << "Release: " << name << '\n'; }
};

int main() {

    // unique pointer
    auto player = std::make_unique<Entity>("Player");

    player->update();

    auto enemy = std::move(player);

    if (!player) {
        std::cout << "Player tidak lagi dimiliki player.\n";
    }

    enemy->update();

    // shared pointer
    auto textureA = std::make_shared<Texture>("stone.png");

    {
        auto textureB = textureA;
        std::cout << "Owners: " << textureA.use_count() << '\n';
    }

    std::cout << "Owners: " << textureA.use_count() << '\n';

    return 0;
}
