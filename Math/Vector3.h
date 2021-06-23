//
// Created by sasch on 22/06/2021.
//
#pragma once
#include "Matrix.h"

class Matrix;
class Vector3 {
public:
    double x, y, z;
    Vector3(int x, int y, int z);
    Vector3 operator+(const Vector3 &a) const;
    Vector3 operator* (const int &a) const;
    Vector3 operator- (const int &a) const;
    void Normalize();
    void Transform(Matrix &m);
};


