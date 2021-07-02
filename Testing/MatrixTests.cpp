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
    auto oldAABB = enemy.GetAABB();
    auto scale = Matrix::getScaleMatrix(Vector3(2,2,2));
    auto origin = Matrix::getTranslationMatrix(-oldCenter.x,-oldCenter.y,-oldCenter.z);
    auto back = Matrix::getTranslationMatrix(oldCenter.x,oldCenter.y,oldCenter.z);
    enemy.transform(back * scale * origin);

    REQUIRE(oldCenter == enemy.Center());
    REQUIRE(enemy.GetAABB().min.x - oldAABB.min.x == -10);
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

TEST_CASE( "Matrix Rotation" ) {

    auto enemy = Enemy();
    auto oldCenter = enemy.Center();
    auto rotation = Matrix::getRotationMatrix(Vector3(0,1,0), oldCenter, 180);
    enemy.transform(rotation);

    // Some rounding issue.
    AABB x = AABB(Vector3(-10,-10,-120), Vector3(10.000000000000002, 10,0));
    REQUIRE(enemy.GetAABB() == x);
}

TEST_CASE("Matrix subtraction"){
    double zeroMatrix[4][4];
    zeroMatrix[0][0] = 0; zeroMatrix[0][1] = 0; zeroMatrix[0][2] = 0; zeroMatrix[0][3] = 0;
    zeroMatrix[1][0] = 0;   zeroMatrix[1][1] = 0;   zeroMatrix[1][2] = 0;  zeroMatrix[1][3] = 0;
    zeroMatrix[2][0] = 0;  zeroMatrix[2][1] = 0;  zeroMatrix[2][2] = 0;   zeroMatrix[2][3] = 0;
    zeroMatrix[3][0] = 0; zeroMatrix[3][1] = 0; zeroMatrix[3][2] = 0;zeroMatrix[3][3] = 0;
    auto matrixA = Matrix(Matrix::getOneMatrix());
    auto matrixB = Matrix(Matrix::getOneMatrix());
    auto x = matrixA - matrixB;
     auto zero = Matrix(zeroMatrix);
    REQUIRE(x == zero);
}



TEST_CASE("Matrix addition"){
    double twoMatrix[4][4];
    twoMatrix[0][0] = 2; twoMatrix[0][1] = 0; twoMatrix[0][2] = 0; twoMatrix[0][3] = 0;
    twoMatrix[1][0] = 0; twoMatrix[1][1] = 2; twoMatrix[1][2] = 0; twoMatrix[1][3] = 0;
    twoMatrix[2][0] = 0; twoMatrix[2][1] = 0; twoMatrix[2][2] = 2; twoMatrix[2][3] = 0;
    twoMatrix[3][0] = 0; twoMatrix[3][1] = 0; twoMatrix[3][2] = 0;twoMatrix[3][3] = 2;
    auto matrixA = Matrix(Matrix::getOneMatrix());
    auto matrixB = Matrix(Matrix::getOneMatrix());
    auto x = matrixA + matrixB;
    auto two = Matrix(twoMatrix);
    REQUIRE(x == two);
}



