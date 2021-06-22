#pragma once

class Matrix{
public:
    double matrix[4][4];

public:
    Matrix();
    Matrix(double mat[4][4]);
    Matrix operator+(const Matrix &m);
    Matrix operator*(const Matrix &m);
    Matrix operator-(const Matrix &m);
    static Matrix getRotationMatrixY(double degrees);
    static Matrix getTranslationMatrix(double tX, double tY, double tZ);
};