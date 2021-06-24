//
// Created by sasch on 23/06/2021.
//

#include "SpaceShip.h"

void SpaceShip::Update(double dt) {

}

SpaceShip::SpaceShip() {

//            verts.emplace_back(Vector3(0, 0, 0)),
//            verts.emplace_back(Vector3(0, 0, -20)),
//            verts.emplace_back(Vector3(-20, 0, -20)),
//            verts.emplace_back(Vector3(-20, 0, 0)),
//            verts.emplace_back(Vector3(0, -20, 0)),
//            verts.emplace_back(Vector3(0, -20, -20)),
//            verts.emplace_back(Vector3(-20, -20, -20)),
//            verts.emplace_back(Vector3(-20, -20, 0)),
//            verts.emplace_back(Vector3(20, -10, -10)),
//            verts.emplace_back(Vector3(-40, -10, -10)),
//            verts.emplace_back(Vector3(-10, -10, 40)),
//
//            lines.emplace_back(Line(verts[0], verts[1]));
//            lines.emplace_back(Line(verts[1], verts[2]));
//            lines.emplace_back(Line(verts[2], verts[3]));
//            lines.emplace_back(Line(verts[3], verts[0]));
//
//            lines.emplace_back(Line(verts[0], verts[4]));
//            lines.emplace_back(Line(verts[1], verts[5]));
//            lines.emplace_back(Line(verts[2], verts[6]));
//            lines.emplace_back(Line(verts[3], verts[7]));
//
//            lines.emplace_back(Line(verts[4], verts[5]));
//            lines.emplace_back(Line(verts[5], verts[6]));
//            lines.emplace_back(Line(verts[6], verts[7]));
//            lines.emplace_back(Line(verts[7], verts[4]));
//
//
//
//            lines.emplace_back(Line(verts[8], verts[5]));
//            lines.emplace_back(Line(verts[8], verts[4]));
//            lines.emplace_back(Line(verts[8], verts[0]));
//            lines.emplace_back(Line(verts[8], verts[1]));
//
//            lines.emplace_back(Line(verts[9], verts[7]));
//            lines.emplace_back(Line(verts[9], verts[6]));
//            lines.emplace_back(Line(verts[9], verts[3]));
//            lines.emplace_back(Line(verts[9], verts[2]));
//
//            lines.emplace_back(Line(verts[10], verts[0]));
//            lines.emplace_back(Line(verts[10], verts[4]));
//            lines.emplace_back(Line(verts[10], verts[7]));
//            lines.emplace_back(Line(verts[10], verts[3]));

    // Cube from example.
    verts.emplace_back(Vector3(10, 10, -50));
    verts.emplace_back(Vector3(10, 10, -70));
    verts.emplace_back(Vector3(-10, 10,-70));
    verts.emplace_back(Vector3(-10, 10,-50));





    verts.emplace_back(Vector3(10, -10, -50));
    verts.emplace_back(Vector3(10, -10, -70));
    verts.emplace_back(Vector3(-10, -10, -70));
    verts.emplace_back(Vector3(-10, -10, -50));

    verts.emplace_back(Vector3(0, 30, -60));




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


    lines.emplace_back(Line(verts[0], verts[8]));
    lines.emplace_back(Line(verts[1], verts[8]));
    lines.emplace_back(Line(verts[2], verts[8]));
    lines.emplace_back(Line(verts[3], verts[8]));



    up =  &lines[4];
}
