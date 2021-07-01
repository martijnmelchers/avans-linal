#ifndef LINALG_SPACESHIP_H
#define LINALG_SPACESHIP_H


#include "Transform.h"

class Transform;
class AABB;
class SpaceShip : public Transform {
public:
    SpaceShip();
    void Update(double dt) override;
    void Collide(Transform* collider) override;
};


#endif //LINALG_SPACESHIP_H
