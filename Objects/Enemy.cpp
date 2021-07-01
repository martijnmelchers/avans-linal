#include "Enemy.h"
#include "Bullet.h"
#include <cmath>
#include <iostream>

void Enemy::Update(double dt) {
    time += dt;

    Pulse(dt);
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


// Pulses the entity in a sine wave.
void Enemy::Pulse(double dt) {
    auto center = Center();
    if(shift != 0){
        auto resetShift = 1/shift;
        auto resetScale = Matrix::getScaleMatrix(Vector3(resetShift, resetShift, resetShift));
        auto resetBack = Matrix::getTranslationMatrix(center.x, center.y, center.z);
        auto resetOrigin = Matrix::getTranslationMatrix(-center.x, -center.y, -center.z);

        transform(resetBack * resetScale * resetOrigin);
    }
    shift = 1 * sin(0.0005 * time + 0.5) + 1.2;

    auto origin = Matrix::getTranslationMatrix(-center.x, -center.y, -center.z);
    auto scale = Matrix::getScaleMatrix(Vector3(shift,shift,shift));
    auto back = Matrix::getTranslationMatrix(center.x, center.y, center.z);

    transform(back * scale * origin);
}

void Enemy::Collide(Transform* collider) {
    if(dynamic_cast<Bullet*>(collider) != nullptr){
        flagDestroy = true;
    }
}
