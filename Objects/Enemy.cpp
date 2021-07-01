#include "Enemy.h"
#include <cmath>
#include <iostream>

void Enemy::Update(double dt) {
    time += dt;
    scaled = false;
    if (!scaled) {
        double shift = 1 * sin(1 * time + 0.5);

        auto center = Center();
        auto origin = Matrix::getTranslationMatrix(-center.x, -center.y, -center.z);
        auto scale = Matrix::getScaleMatrix(Vector3(shift, shift, shift));

        auto back = Matrix::getTranslationMatrix(center.x, center.y, center.z);

        //   transform(scale);

        scaled = true;
    }

}

Enemy::Enemy() {

    // Cube from example.
    verts.emplace_back(Vector3(10, 10, -100));
    verts.emplace_back(Vector3(10, 10, -120));
    verts.emplace_back(Vector3(-10, 10, -120));
    verts.emplace_back(Vector3(-10, 10, -100));


    verts.emplace_back(Vector3(10, -10, -100));
    verts.emplace_back(Vector3(10, -10, -120));
    verts.emplace_back(Vector3(-10, -10, -120));
    verts.emplace_back(Vector3(-10, -10, -100));


    lines.emplace_back(Line(verts[0], verts[1]));
    lines.emplace_back(Line(verts[1], verts[2]));
    lines.emplace_back(Line(verts[2], verts[3]));
    lines.emplace_back(Line(verts[3], verts[0]));
    lines.emplace_back(Line(verts[0], verts[4]));
    lines.emplace_back(Line(verts[1], verts[5]));
    lines.emplace_back(Line(verts[2], verts[6]));
    lines.emplace_back(Line(verts[3], verts[7]));
    lines.emplace_back(Line(verts[4], verts[5]));
    lines.emplace_back(Line(verts[5], verts[6]));
    lines.emplace_back(Line(verts[6], verts[7]));
    lines.emplace_back(Line(verts[7], verts[4]));


    up = &lines[4];
}
