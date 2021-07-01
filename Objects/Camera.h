#pragma once

#include "Transform.h"

class Camera : public Transform {
public:
    Vector3 eye;
    Vector3 lookAt;
    Vector3 up = Vector3(0, 1, 0);

    Camera(const Vector3& eye, const Vector3& lookAt);

    void Update(double dt) override;
    void Collide(Transform* collider) override;
    Matrix GetCameraTMatrix() const;
};


