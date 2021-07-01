#include <cmath>
#include "Vector3.h"

Vector3 Vector3::operator+(const Vector3 &a) const {
    return Vector3(x + a.x, y + a.y, z + a.z);
}

Vector3 Vector3::operator*(const double &a) const {
    return Vector3(x * a, y * a, z * a);
}

Vector3 Vector3::operator-(const double &a) const {
    return Vector3(x - a, y - a, z - a);
}

Vector3::Vector3(const double x, const double y, const double z) : x(x), y(y), z(z) {
    w = 1;
}

void Vector3::Transform(const Matrix &m) {
    double nx = m.matrix[0][0] * x + m.matrix[0][1] * y + m.matrix[0][2] * z + m.matrix[0][3] * w;
    double ny = m.matrix[1][0] * x + m.matrix[1][1] * y + m.matrix[1][2] * z + m.matrix[1][3] * w;
    double nz = m.matrix[2][0] * x + m.matrix[2][1] * y + m.matrix[2][2] * z + m.matrix[2][3] * w;
    double nw = m.matrix[3][0] * x + m.matrix[3][1] * y + m.matrix[3][2] * z + m.matrix[3][3] * w;
    x = nx;
    y = ny;
    z = nz;
    w = nw;
}

void Vector3::Normalize() {
    const double length = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    if (length == 0) {
        x = 0;
        y = 0;
        z = 0;
        return;
    }
    x = x / length;
    y = y / length;
    z = z / length;
}

Vector3 Vector3::GetPerspective(const Matrix &perspectiveMatrix) const {
    double nx = perspectiveMatrix.matrix[0][0] * x + perspectiveMatrix.matrix[0][1] * y +
                perspectiveMatrix.matrix[0][2] * z + perspectiveMatrix.matrix[0][3] * w;
    double ny = perspectiveMatrix.matrix[1][0] * x + perspectiveMatrix.matrix[1][1] * y +
                perspectiveMatrix.matrix[1][2] * z + perspectiveMatrix.matrix[1][3] * w;
    double nz = perspectiveMatrix.matrix[2][0] * x + perspectiveMatrix.matrix[2][1] * y +
                perspectiveMatrix.matrix[2][2] * z + perspectiveMatrix.matrix[2][3] * w;
    double nw = perspectiveMatrix.matrix[3][0] * x + perspectiveMatrix.matrix[3][1] * y +
                perspectiveMatrix.matrix[3][2] * z + perspectiveMatrix.matrix[3][3] * w;

    return Vector3(nx, ny, nz, nw);
}

Vector3::Vector3(const double x, const double y, const double z, const double w) : x(x), y(y), z(z), w(w) {

}


// Calculate Dot product from current vector and the given.
double Vector3::DotProduct(const Vector3 &m) const {
    double x = x * m.x + y * m.y + z * m.z;

    double aLength = (pow(x, 2) + pow(y, 2) + pow(z, 2));
    double bLength = (pow(m.x, 2) + pow(m.y, 2) + pow(m.z, 2));

    double ab = sqrt(aLength + bLength);

    double angle = acos(ab) / 180.0 * M_PI;
    return angle;
}

Vector3 Vector3::CrossProduct(const Vector3 &w) const {
    double nx, ny, nz;
    nx = y * w.z - z * w.y;
    ny = z * w.x - x * w.z;
    nz = x * w.y - y * w.x;
    return Vector3(nx, ny, nz);
}

Vector3 Vector3::operator-(const Vector3 &a) const {
    return Vector3(x - a.x, y - a.y, z - a.z);
}

Vector3 Vector3::operator*(const Vector3 &a) const {
    return Vector3(x * a.x, y * a.y, z * a.z);
}
