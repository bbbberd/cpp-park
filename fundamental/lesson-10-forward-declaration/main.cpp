#include "Camera.h"
#include "Player.h"

int main() {
    Camera camera;
    Player player;

    player.setCamera(&camera);
    player.LookAtCamera();

    return 0;
}
