//
// Created by sasch on 22/06/2021.
//

#include <cmath>
#include "Vector3.h"

Vector3 Vector3::operator+(const Vector3 &a) const {
    return Vector3(x + a.x, y + a.y, z + a.z);
}

Vector3 Vector3::operator*(const int &a) const {
    return Vector3(x * a, y * a, z * a);
}

Vector3 Vector3::operator-(const int &a) const {
    return Vector3(x - a, y - a, z -a );
}
Vector3::Vector3(int x, int y, int z) : x(x), y(y), z(z){

}

void Vector3::Transform(Matrix &m) {
    double nx = m.matrix[0][0]*x + m.matrix[0][1]*y + m.matrix[0][2]*z + m.matrix[0][3] * 1;
    double ny = m.matrix[1][0]*x + m.matrix[1][1]*y + m.matrix[1][2]*z + m.matrix[1][3] * 1;
    double nz = m.matrix[2][0]*x + m.matrix[2][1]*y + m.matrix[2][2]*z + m.matrix[2][3] * 1;

    x = nx;
    y = ny;
    z = nz;
}

void Vector3::Normalize() {
    const double length = sqrt(pow(x, 2) + pow(y,2) + pow(z, 2));
    x = x / length;
    y = y / length;
    z = z / length;
}
