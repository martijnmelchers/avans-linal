#pragma once
#include "Matrix.h"

class Matrix;
class Vector3 {
public:
    double x, y, z, w;
    Vector3(const double x, const double y, const double z);
    Vector3(const double x, const double y, const double z, const double w);
    Vector3 operator+(const Vector3 &input) const;
    Vector3 operator*(const Vector3 &input) const;
    bool operator==(const Vector3 &a) const;
    Vector3 operator* (const double &input) const;
    Vector3 operator- (const double &input) const;
    Vector3 operator- (const Vector3 &a) const;
    void Normalize();
    void Transform(const Matrix &input);
    Vector3 GetPerspective(const Matrix& perspectiveMatrix) const;
    double DotProduct(const Vector3 &input) const;
    Vector3 CrossProduct(const Vector3 &w) const;
};


