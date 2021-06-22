//
// Created by sasch on 22/06/2021.
//

#include "Matrix.h"
#include <math.h>       /* cos */

Matrix Matrix::operator*(const Matrix &m) {
    double newMatrix[4][4];

    for (int i = 0; i < sizeof(matrix); i++) {
        for(int j = 0; j < sizeof(m.matrix); j++) {
            newMatrix[i][j] = matrix[i][0]*m.matrix[0][j] + matrix[i][1]*m.matrix[1][j] + matrix[i][2]*m.matrix[2][j] + matrix[i][3]*m.matrix[3][j];
        }
    }
    return Matrix(newMatrix);
}

Matrix::Matrix(double mat[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            matrix[j][i] = mat[j][i];
        }
    }
}

Matrix Matrix::getTranslationMatrix(double tX, double tY, double tZ) {
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

