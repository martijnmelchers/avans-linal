//
// Created by sasch on 25/06/2021.
//

#include "Camera.h"

void Camera::Update(double dt) {

}

Camera::Camera(Vector3 eye, Vector3 lookAt) : eye(eye), lookAt(lookAt) {

}

Matrix Camera::getCameraTMatrix() {
    // Normaliseer alles voor de transformatie.


    direction = eye - lookAt;
    right = up.CrossProduct(direction);
    up = direction.CrossProduct(right);

    direction.Normalize();
    right.Normalize();
    up.Normalize();

    auto origin = Matrix::getTranslationMatrix(-eye.x, -eye.y, -eye.z);
    auto tMatrix = Matrix::getCameraMatrix(right, up, direction);

    return (origin * tMatrix);
}
