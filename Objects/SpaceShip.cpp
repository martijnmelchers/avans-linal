#include "SpaceShip.h"
#include "Enemy.h"

void SpaceShip::Update(double dt) {

}

SpaceShip::SpaceShip() {
    // Cube from example.
    verts.emplace_back(Vector3(10, 10, -50));
    verts.emplace_back(Vector3(10, 10, -70));
    verts.emplace_back(Vector3(-10, 10, -70));
    verts.emplace_back(Vector3(-10, 10, -50));


    verts.emplace_back(Vector3(10, -10, -50));
    verts.emplace_back(Vector3(10, -10, -70));
    verts.emplace_back(Vector3(-10, -10, -70));
    verts.emplace_back(Vector3(-10, -10, -50));

    verts.emplace_back(Vector3(0, 0, -90));
    verts.emplace_back(Vector3(-50, 0, -60));
    verts.emplace_back(Vector3(50, 0, -60));


    lines.emplace_back(Line(verts[0], verts[1])); //bottom
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


    lines.emplace_back(Line(verts[1], verts[8]));
    lines.emplace_back(Line(verts[2], verts[8]));
    lines.emplace_back(Line(verts[5], verts[8]));
    lines.emplace_back(Line(verts[6], verts[8]));


    lines.emplace_back(Line(verts[2], verts[9]));
    lines.emplace_back(Line(verts[3], verts[9]));
    lines.emplace_back(Line(verts[6], verts[9]));
    lines.emplace_back(Line(verts[7], verts[9]));


    lines.emplace_back(Line(verts[4], verts[10]));
    lines.emplace_back(Line(verts[5], verts[10]));
    lines.emplace_back(Line(verts[1], verts[10]));
    lines.emplace_back(Line(verts[0], verts[10]));

    up = &lines[4];
    forward = &lines[0];
}

void SpaceShip::Collide(Transform* collider) {
    if(dynamic_cast<Enemy*>(collider) != nullptr){
       // flagDestroy = true;
    }
}
