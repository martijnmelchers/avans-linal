//
// Created by sasch on 22/06/2021.
//

#ifndef LINALG_VECTOR3_H
#define LINALG_VECTOR3_H

#include "Matrix.h"
class Vector3 {
public:
    double x, y, z;
    Vector3(int x, int y, int z);
    Vector3 operator+(const Vector3 &a) const;
    Vector3 operator* (const int &a) const;
    Vector3 operator- (const int &a) const;

    void Transform(Matrix &m);
};


#endif //LINALG_VECTOR3_H
