#pragma once

class Camera;

class Player {
  public:
    Player();

    void setCamera(Camera *camera);
    void LookAtCamera();

  private:
    Camera *camera;
};
