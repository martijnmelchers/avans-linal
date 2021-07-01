//
// Created by sasch on 01/07/2021.
//

#ifndef LINALG_BULLET_H
#define LINALG_BULLET_H


#include "Transform.h"
#include "SpaceShip.h"
#include "Enemy.h"


class SpaceShip;
class Bullet : public Transform {
private:
    Vector3 direction;
    Enemy& enemy;
public:
    Bullet(const Vector3& spawmPoint, const Vector3& direction, Enemy& enemy);
    void Update(double dt) override;
    void Collide(Transform* collider) override;
};


#endif //LINALG_BULLET_H
