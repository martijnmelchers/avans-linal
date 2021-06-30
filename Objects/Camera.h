//
// Created by sasch on 25/06/2021.
//
#pragma once
#include "Transform.h"

class Camera: public Transform {
public:
    Vector3 eye;
    Vector3 lookAt;
    Vector3 up = Vector3(0,1,0);
    Camera(Vector3 eye, Vector3 lookAt);
    void Update(double dt) override;
    Matrix getCameraTMatrix();
};


