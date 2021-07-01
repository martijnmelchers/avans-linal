#pragma once

#include "Vector3.h"


class Vector3;

class Matrix {
public:
    double matrix[4][4]{};

public:
    Matrix();

    Matrix(double mat[4][4]);

    Matrix operator+(const Matrix &m);

    Matrix operator*(const Matrix &m);

    Matrix operator*=(const Matrix &m);

    Matrix operator-(const Matrix &m);

    /* Start "M3" */
    static Matrix getRotationMatrixY(double degrees);

    static Matrix getRotationMatrixX(double degrees);

    static Matrix getRotationMatrixZ(double degrees);

    /* End "M3" */
    static Matrix getRotationMatrixM1(Vector3 &axis);

    static Matrix getRotationMatrixM2(Vector3 &axis);

    static Matrix getRotationMatrixM4(Vector3 &axis);

    static Matrix getRotationMatrixM5(Vector3 &axis);

    static Matrix getScaleMatrix(const Vector3 &scale);

    static Matrix getPerspectiveMatrix(double far, double near, double scale);

    static Matrix getCameraMatrix(const Vector3 &right, const Vector3 &up, const Vector3 &direction);

    static Matrix getRotationMatrix(Vector3 &axis, Vector3 &center, const double angle);

    static Matrix getTranslationMatrix(double tX, double tY, double tZ);
};