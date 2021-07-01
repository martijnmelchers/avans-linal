#include "Camera.h"

void Camera::Update(double dt) {

}

Camera::Camera(const Vector3& eye, const Vector3& lookAt) : eye(eye), lookAt(lookAt) {

}

Matrix Camera::GetCameraTMatrix() const {
    // Normaliseer alles voor de transformatie.
    auto dir = eye - lookAt;
    dir.Normalize();
    auto ri = up.CrossProduct(dir);
    ri.Normalize();
    auto upN = dir.CrossProduct(ri);
    upN.Normalize();

    auto origin = Matrix::getTranslationMatrix(-eye.x, -eye.y, -eye.z);
    auto tMatrix = Matrix::getCameraMatrix(ri, upN, dir);

    return (origin * tMatrix);
}

void Camera::Collide(Transform *collider) {

}
