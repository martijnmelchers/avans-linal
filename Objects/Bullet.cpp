//
// Created by sasch on 01/07/2021.
//

#include <iostream>
#include "Bullet.h"
#include "SpaceShip.h"
#include "AABB.h"

void Bullet::Update(double dt) {
    auto dir = direction * dt * 0.05;
    transform(Matrix::getTranslationMatrix(dir.x, dir.y, dir.z));
}

Bullet::Bullet(const Vector3& spawmPoint, const Vector3& direction, Enemy& enemy): direction(direction), enemy(enemy) {


    verts.emplace_back(Vector3(1, 1, 0));
    verts.emplace_back(Vector3(1, 1, 3));
    verts.emplace_back(Vector3(-1, 1, 3));
    verts.emplace_back(Vector3(-1, 1, 0));


    verts.emplace_back(Vector3(1, -1, 0));
    verts.emplace_back(Vector3(1, -1, 3));
    verts.emplace_back(Vector3(-1, -1, 3));
    verts.emplace_back(Vector3(-1, -1, 0));


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



    auto pos = spawmPoint - Center();

    transform(Matrix::getTranslationMatrix(pos.x,pos.y,pos.z));

}

void Bullet::Collide(Transform *override) {
    if(dynamic_cast<SpaceShip*>(override) == nullptr){
        flagDestroy = true;
    }
}
