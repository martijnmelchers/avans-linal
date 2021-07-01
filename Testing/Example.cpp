//
// Created by sasch on 01/07/2021.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch_amalgamated.hpp"
#include "../Objects/Enemy.h"


TEST_CASE( "Matrix translation" ) {
    auto enemy = Enemy();
    auto oldCenter = enemy.Center();
    auto trans = Matrix::getTranslationMatrix(1,1,1);
    enemy.transform(trans);
    REQUIRE(enemy.Center() == Vector3(oldCenter.x + 1, oldCenter.y +1, oldCenter.z + 1));
}


TEST_CASE( "Matrix scaling" ) {
    auto enemy = Enemy();
    auto oldCenter = enemy.Center();
    auto scale = Matrix::getScaleMatrix(Vector3(2,2,2));
    auto origin = Matrix::getTranslationMatrix(-oldCenter.x,-oldCenter.y,-oldCenter.z);
    auto back = Matrix::getTranslationMatrix(oldCenter.x,oldCenter.y,oldCenter.z);
    enemy.transform(back * scale * origin);

    REQUIRE(oldCenter == enemy.Center());
}

TEST_CASE( "Matrix multiplication" ) {

    double matrixone[4][4];
    matrixone[0][0] = 1; matrixone[0][1] = 0; matrixone[0][2] = 0; matrixone[0][3] = 0;
    matrixone[1][0] = 0;   matrixone[1][1] = 1;   matrixone[1][2] = 0;  matrixone[1][3] = 0;
    matrixone[2][0] = 0;  matrixone[2][1] = 0;  matrixone[2][2] = 1;   matrixone[2][3] = 0;
    matrixone[3][0] = 0; matrixone[3][1] = 0; matrixone[3][2] = 0;matrixone[3][3] = 1;

    auto enemy = Enemy();
    auto oldCenter = enemy.Center();
    enemy.transform(Matrix(matrixone) * Matrix(matrixone));


    REQUIRE(enemy.Center() == oldCenter);
}

