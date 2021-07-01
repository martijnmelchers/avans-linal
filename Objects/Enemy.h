//
// Created by sasch on 23/06/2021.
//

#ifndef LINALG_ENEMY_H
#define LINALG_ENEMY_H


#include "Transform.h"

class Transform;
class Enemy : public Transform {
public:
    Enemy();
    void Update(double dt) override;
private:
    double time = 0;
    bool scaled = false;
    Vector3 originalCenter = this->Center();
};


#endif //LINALG_ENEMY_H
