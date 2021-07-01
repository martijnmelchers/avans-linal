#ifndef LINALG_ENEMY_H
#define LINALG_ENEMY_H


#include "Transform.h"

class Transform;

class Enemy : public Transform {
public:
    Enemy();

    void Update(double dt) override;
    void Pulse(double dt);
    void Collide(Transform* collider) override;

private:
    double time = 0;
    double shift = 0;
};


#endif //LINALG_ENEMY_H
