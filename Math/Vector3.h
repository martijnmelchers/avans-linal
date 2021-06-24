//
// Created by sasch on 22/06/2021.
//
#pragma once
#include "Matrix.h"

class Matrix;
class Vector3 {
public:
    double x, y, z, w;
    Vector3(double x, double y, double z);
    Vector3(double x, double y, double z, double w);
    Vector3 operator+(const Vector3 &a) const;
    Vector3 operator* (const double &a) const;
    Vector3 operator- (const double &a) const;
    void Normalize();
    void Transform(Matrix &m);
    Vector3 GetPerspective(Matrix perspectiveMatrix) const;
};


