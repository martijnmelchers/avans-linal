//
// Created by sasch on 23/06/2021.
//

#ifndef LINALG_SPACESHIP_H
#define LINALG_SPACESHIP_H


#include "Transform.h"

class Transform;
class SpaceShip : public Transform {
public:
    SpaceShip();
    void Update(double dt) override;

};


#endif //LINALG_SPACESHIP_H
