#include <iostream>
#include <string>
#include <variant>

// different types of game events
struct damageEvent {
    int damage;
};

struct healEvent {
    int amount;
};

struct messageEvent {
    std::string message;
};

// a game event can hold exactly one of these types.
using gameEvent = std::variant<damageEvent, healEvent, messageEvent>;

void handleEvent(const gameEvent &event) {
    std::visit(
        [](const auto &currentEvent) {
            using T = std::decay_t<decltype(currentEvent)>;
            if constexpr (std::is_same_v<T, damageEvent>) {
                std::cout << "Damage: " << currentEvent.damage << '\n';
            } else if constexpr (std::is_same_v<T, healEvent>) {
                std::cout << "Heal: " << currentEvent.amount << '\n';
            } else if constexpr (std::is_same_v<T, messageEvent>) {
                std::cout << "Message: " << currentEvent.message << '\n';
            }
        },
        event);
}

int main() {
    gameEvent damage = damageEvent{50};
    gameEvent heal = healEvent{25};
    gameEvent message = messageEvent{"Player entered the area"};

    handleEvent(damage);
    handleEvent(heal);
    handleEvent(message);

    return 0;
}
