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
