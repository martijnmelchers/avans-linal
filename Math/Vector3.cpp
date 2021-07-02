#include <cmath>
#include "Vector3.h"

Vector3 Vector3::operator+(const Vector3 &input) const {
    return Vector3(this->x + input.x, this->y + input.y, this->z + input.z, this->w + input.w);
}

Vector3 Vector3::operator*(const double &input) const {
    return Vector3(this->x * input, this->y * input, this->z * input);
}

Vector3 Vector3::operator-(const double &input) const {
    return Vector3(this->x - input, this->y - input, this->z - input);
}

Vector3::Vector3(const double x, const double y, const double z) : x(x), y(y), z(z) {
    this->w = 1;
}

void Vector3::Transform(const Matrix &input) {
    double nx = input.matrix[0][0] * this->x + input.matrix[0][1] * this->y + input.matrix[0][2] * this->z + input.matrix[0][3] * this->w;
    double ny = input.matrix[1][0] * this->x + input.matrix[1][1] * this->y + input.matrix[1][2] * this->z + input.matrix[1][3] * this->w;
    double nz = input.matrix[2][0] * this->x + input.matrix[2][1] * this->y + input.matrix[2][2] * this->z + input.matrix[2][3] * this->w;
    double nw = input.matrix[3][0] * this->x + input.matrix[3][1] * this->y + input.matrix[3][2] * this->z + input.matrix[3][3] * this->w;
    x = nx;
    y = ny;
    z = nz;
    w = nw;
}

void Vector3::Normalize() {
    const double length = sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));

    x = x / length;
    y = y / length;
    z = z / length;
}

Vector3 Vector3::GetPerspective(const Matrix &perspectiveMatrix) const {
    double nx = perspectiveMatrix.matrix[0][0] * this->x + perspectiveMatrix.matrix[0][1] * this->y +
                perspectiveMatrix.matrix[0][2] * this->z + perspectiveMatrix.matrix[0][3] * this->w;
    double ny = perspectiveMatrix.matrix[1][0] * this->x + perspectiveMatrix.matrix[1][1] * this->y +
                perspectiveMatrix.matrix[1][2] * this->z + perspectiveMatrix.matrix[1][3] * this->w;
    double nz = perspectiveMatrix.matrix[2][0] * this->x + perspectiveMatrix.matrix[2][1] * this->y +
                perspectiveMatrix.matrix[2][2] * this->z + perspectiveMatrix.matrix[2][3] * this->w;
    double nw = perspectiveMatrix.matrix[3][0] * this->x + perspectiveMatrix.matrix[3][1] * this->y +
                perspectiveMatrix.matrix[3][2] * this->z + perspectiveMatrix.matrix[3][3] * this->w;

    return Vector3(nx, ny, nz, nw);
}

Vector3::Vector3(const double x, const double y, const double z, const double w) : x(x), y(y), z(z), w(w) {

}


// Calculate Dot product from current vector and the given.
double Vector3::DotProduct(const Vector3 &input) const {
    double aLength = (pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
    double bLength = (pow(input.x, 2) + pow(input.y, 2) + pow(input.z, 2));

    double ab = sqrt(aLength + bLength);

    double angle = acos(ab) / 180.0 * M_PI;
    return angle;
}

Vector3 Vector3::CrossProduct(const Vector3 &input) const {
    double nx, ny, nz;
    nx = this->y * input.z - this->z * input.y;
    ny = this->z * input.x - this->x * input.z;
    nz = this->x * input.y - this->y * input.x;

    return Vector3(nx, ny, nz);
}

Vector3 Vector3::operator-(const Vector3 &input) const {
    return Vector3(this->x - input.x, this->y - input.y, this->z - input.z, this->w - input.w);
}

Vector3 Vector3::operator*(const Vector3 &input) const {
    return Vector3(this->x * input.x, this->y * input.y, this->z * input.z, this->w * input.w);
}
