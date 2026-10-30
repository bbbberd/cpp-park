#include "Player.h"
#include "Camera.h"

Player::Player() : camera(nullptr) {}

void Player::setCamera(Camera *camera) { this->camera = camera; }

void Player::LookAtCamera() {
    if (camera != nullptr)
        camera->printName();
}
