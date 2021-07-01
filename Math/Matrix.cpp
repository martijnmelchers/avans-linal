#include "Matrix.h"
#include <math.h>       /* cos */

Matrix Matrix::operator*(const Matrix &m) {
    double newMatrix[4][4];

    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            newMatrix[x][y] =
                    matrix[x][0] * m.matrix[0][y] +
                    matrix[x][1] * m.matrix[1][y] +
                    matrix[x][2] * m.matrix[2][y] +
                    matrix[x][3] * m.matrix[3][y];
        }
    }
    return Matrix(newMatrix);
}


Matrix::Matrix(const double mat[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[j][i] = mat[j][i];
        }
    }
}

Matrix Matrix::getTranslationMatrix(double tX, double tY, double tZ)  {
    double m[4][4];
    m[0][0] = 1.0;
    m[0][1] = 0.0;
    m[0][2] = 0.0;
    m[0][3] = tX;
    m[1][0] = 0.0;
    m[1][1] = 1.0;
    m[1][2] = 0.0;
    m[1][3] = tY;
    m[2][0] = 0.0;
    m[2][1] = 0.0;
    m[2][2] = 1.0;
    m[2][3] = tZ;
    m[3][0] = 0.0;
    m[3][1] = 0.0;
    m[3][2] = 0.0;
    m[3][3] = 1.0;
    return Matrix(m);
}


Matrix Matrix::getRotationMatrixY(double degrees) {
    double radians = degrees / 180.0 * M_PI;
    double m[4][4];

    m[0][0] = cos(radians);
    m[0][1] = 0.0;
    m[0][2] = sin(radians);
    m[0][3] = 0.0;
    m[1][0] = 0.0;
    m[1][1] = 1.0;
    m[1][2] = 0.0;
    m[1][3] = 0.0;
    m[2][0] = -sin(radians);
    m[2][1] = 0.0;
    m[2][2] = cos(radians);
    m[2][3] = 0.0;
    m[3][0] = 0.0;
    m[3][1] = 0.0;
    m[3][2] = 0.0;
    m[3][3] = 1.0;

    return m;
}

Matrix Matrix::operator*=(const Matrix &m) {
    *this = *this * m;
    return *this;
}


// Draai axis naar het xy vlak om y heen.
Matrix Matrix::getRotationMatrixM1(const Vector3 &axis) {
    double newMatrix[4][4];
    // Bereken de hoek die we moeten draaien om y heen.
    // XZ Line
    const double XZ = sqrt(axis.x * axis.x + axis.z * axis.z);

    // Als XZ 0 is, geef een eenheidsmatrix terug;

    if (XZ == 0) {
        newMatrix[0][0] = 1.0;
        newMatrix[0][1] = 0.0;
        newMatrix[0][2] = 0.0;
        newMatrix[0][3] = 0.0;
        newMatrix[1][0] = 0.0;
        newMatrix[1][1] = 1.0;
        newMatrix[1][2] = 0.0;
        newMatrix[1][3] = 0.0;
        newMatrix[2][0] = 0.0;
        newMatrix[2][1] = 0.0;
        newMatrix[2][2] = 1.0;
        newMatrix[2][3] = 0.0;
        newMatrix[3][0] = 0.0;
        newMatrix[3][1] = 0.0;
        newMatrix[3][2] = 0.0;
        newMatrix[3][3] = 1.0;
        return Matrix(newMatrix);
    }

    newMatrix[0][0] = axis.x / XZ;
    newMatrix[0][1] = 0.0;
    newMatrix[0][2] = axis.z / XZ;
    newMatrix[0][3] = 0.0;
    newMatrix[1][0] = 0.0;
    newMatrix[1][1] = 1.0;
    newMatrix[1][2] = 0.0;
    newMatrix[1][3] = 0.0;
    newMatrix[2][0] = -axis.z / XZ;
    newMatrix[2][1] = 0.0;
    newMatrix[2][2] = axis.x / XZ;
    newMatrix[2][3] = 0.0;
    newMatrix[3][0] = 0.0;
    newMatrix[3][1] = 0.0;
    newMatrix[3][2] = 0.0;
    newMatrix[3][3] = 1.0;

    return Matrix(newMatrix);
}


// Draai axis naar x toe om z heen.
Matrix Matrix::getRotationMatrixM2(const Vector3 &axis) {
    double newMatrix[4][4];

    double XZ = sqrt(pow(axis.x, 2) + pow(axis.z, 2));
    double XYZ = sqrt(pow(axis.x, 2) + pow(axis.y, 2) + pow(axis.z, 2));

    newMatrix[0][0] = XZ / XYZ;
    newMatrix[0][1] = axis.y / XYZ;
    newMatrix[0][2] = 0.0;
    newMatrix[0][3] = 0.0;
    newMatrix[1][0] = -axis.y / XYZ;
    newMatrix[1][1] = XZ / XYZ;
    newMatrix[1][2] = 0.0;
    newMatrix[1][3] = 0.0;
    newMatrix[2][0] = 0.0;
    newMatrix[2][1] = 0.0;
    newMatrix[2][2] = 1.0;
    newMatrix[2][3] = 0.0;
    newMatrix[3][0] = 0.0;
    newMatrix[3][1] = 0.0;
    newMatrix[3][2] = 0.0;
    newMatrix[3][3] = 1.0;

    return Matrix(newMatrix);
}

// Draai axis terug naar het xy vlak om z.
Matrix Matrix::getRotationMatrixM4(const Vector3 &axis) {
    double newMatrix[4][4];

    double XZ = sqrt(pow(axis.x, 2) + pow(axis.z, 2));
    double XYZ = sqrt(pow(axis.x, 2) + pow(axis.y, 2) + pow(axis.z, 2));

    newMatrix[0][0] = XZ / XYZ;
    newMatrix[0][1] = -axis.y / XYZ;
    newMatrix[0][2] = 0.0;
    newMatrix[0][3] = 0.0;
    newMatrix[1][0] = axis.y / XYZ;
    newMatrix[1][1] = XZ / XYZ;
    newMatrix[1][2] = 0.0;
    newMatrix[1][3] = 0.0;
    newMatrix[2][0] = 0.0;
    newMatrix[2][1] = 0.0;
    newMatrix[2][2] = 1.0;
    newMatrix[2][3] = 0.0;
    newMatrix[3][0] = 0.0;
    newMatrix[3][1] = 0.0;
    newMatrix[3][2] = 0.0;
    newMatrix[3][3] = 1.0;

    return Matrix(newMatrix);
}

// Draai axis terug naar originele positie om y.
Matrix Matrix::getRotationMatrixM5(const Vector3 &axis) {
    double newMatrix[4][4];

    double XZ = sqrt(pow(axis.x, 2) + pow(axis.z, 2));

    if (XZ == 0.0) {
        newMatrix[0][0] = 1.0;
        newMatrix[0][1] = 0.0;
        newMatrix[0][2] = 0.0;
        newMatrix[0][3] = 0.0;
        newMatrix[1][0] = 0.0;
        newMatrix[1][1] = 1.0;
        newMatrix[1][2] = 0.0;
        newMatrix[1][3] = 0.0;
        newMatrix[2][0] = 0.0;
        newMatrix[2][1] = 0.0;
        newMatrix[2][2] = 1.0;
        newMatrix[2][3] = 0.0;
        newMatrix[3][0] = 0.0;
        newMatrix[3][1] = 0.0;
        newMatrix[3][2] = 0.0;
        newMatrix[3][3] = 1.0;
    } else {
        newMatrix[0][0] = axis.x / XZ;
        newMatrix[0][1] = 0.0;
        newMatrix[0][2] = -axis.z / XZ;
        newMatrix[0][3] = 0.0;
        newMatrix[1][0] = 0.0;
        newMatrix[1][1] = 1.0;
        newMatrix[1][2] = 0.0;
        newMatrix[1][3] = 0.0;
        newMatrix[2][0] = axis.z / XZ;
        newMatrix[2][1] = 0.0;
        newMatrix[2][2] = axis.x / XZ;
        newMatrix[2][3] = 0.0;
        newMatrix[3][0] = 0.0;
        newMatrix[3][1] = 0.0;
        newMatrix[3][2] = 0.0;
        newMatrix[3][3] = 1.0;
    }
    return newMatrix;
}

Matrix Matrix::getRotationMatrix(const Vector3 &axis, const Vector3 &center, const double angle) {
    Matrix origin = Matrix::getTranslationMatrix(-center.x, -center.y, -center.z);

    Matrix m1 = Matrix::getRotationMatrixM1(axis);
    Matrix m2 = Matrix::getRotationMatrixM2(axis);
    Matrix m3 = Matrix::getRotationMatrixX(angle); // Doe daadwerkelijke rotatie.
    Matrix m4 = Matrix::getRotationMatrixM4(axis);
    Matrix m5 = Matrix::getRotationMatrixM5(axis);

    Matrix reverse = Matrix::getTranslationMatrix(center.x, center.y, center.z);


    Matrix newMatrix = m1 * origin;
    newMatrix = m2 * newMatrix;
    newMatrix = m3 * newMatrix;
    newMatrix = m4 * newMatrix;
    newMatrix = m5 * newMatrix;
    newMatrix = reverse * newMatrix;

    return newMatrix;
}

Matrix Matrix::getRotationMatrixX(double degrees) {
    double angle = degrees / 180.0 * M_PI;

    double newMatrix[4][4];

    newMatrix[0][0] = 1.0;
    newMatrix[0][1] = 0.0;
    newMatrix[0][2] = 0.0;
    newMatrix[0][3] = 0.0;
    newMatrix[1][0] = 0.0;
    newMatrix[1][1] = cos(angle);
    newMatrix[1][2] = -sin(angle);
    newMatrix[1][3] = 0.0;
    newMatrix[2][0] = 0.0;
    newMatrix[2][1] = sin(angle);
    newMatrix[2][2] = cos(angle);
    newMatrix[2][3] = 0.0;
    newMatrix[3][0] = 0.0;
    newMatrix[3][1] = 0.0;
    newMatrix[3][2] = 0.0;
    newMatrix[3][3] = 1.0;

    return newMatrix;
}

Matrix Matrix::getPerspectiveMatrix(double far, double near, double scale) {
    double perspectiveMatrix[4][4];

    perspectiveMatrix[0][0] = scale;
    perspectiveMatrix[0][1] = 0;
    perspectiveMatrix[0][2] = 0;
    perspectiveMatrix[0][3] = 0;
    perspectiveMatrix[1][0] = 0;
    perspectiveMatrix[1][1] = scale;
    perspectiveMatrix[1][2] = 0;
    perspectiveMatrix[1][3] = 0;
    perspectiveMatrix[2][0] = 0;
    perspectiveMatrix[2][1] = 0;
    perspectiveMatrix[2][2] = -far / (far - near);
    perspectiveMatrix[2][3] = -1;
    perspectiveMatrix[3][0] = 0;
    perspectiveMatrix[3][1] = 0;
    perspectiveMatrix[3][2] = -(far * near) / (far - near);
    perspectiveMatrix[3][3] = 0;

    return Matrix(perspectiveMatrix);
}

Matrix Matrix::getCameraMatrix(const Vector3 &right, const Vector3 &up, const Vector3 &direction) {
    double newMatrix[4][4];
    newMatrix[0][0] = right.x;
    newMatrix[0][1] = right.y;
    newMatrix[0][2] = right.z;
    newMatrix[0][3] = 0;
    newMatrix[1][0] = up.x;
    newMatrix[1][1] = up.y;
    newMatrix[1][2] = up.z;
    newMatrix[1][3] = 0;
    newMatrix[2][0] = direction.x;
    newMatrix[2][1] = direction.y;
    newMatrix[2][2] = direction.z;
    newMatrix[2][3] = 0;
    newMatrix[3][0] = 0;
    newMatrix[3][1] = 0;
    newMatrix[3][2] = 0;
    newMatrix[3][3] = 1;

    return Matrix(newMatrix);
}

Matrix::Matrix() = default;

Matrix Matrix::getScaleMatrix(const Vector3 &scale) {
    double newMatrix[4][4];
    newMatrix[0][0] = scale.x;
    newMatrix[0][1] = 0;
    newMatrix[0][2] = 0;
    newMatrix[0][3] = 0;
    newMatrix[1][0] = 0;
    newMatrix[1][1] = scale.y;
    newMatrix[1][2] = 0;
    newMatrix[1][3] = 0;
    newMatrix[2][0] = 0;
    newMatrix[2][1] = 0;
    newMatrix[2][2] = scale.z;
    newMatrix[2][3] = 0;
    newMatrix[3][0] = 0;
    newMatrix[3][1] = 0;
    newMatrix[3][2] = 0;
    newMatrix[3][3] = 1;
    return Matrix(newMatrix);
}



