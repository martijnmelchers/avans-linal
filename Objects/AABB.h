//
// Created by sasch on 01/07/2021.
//

#ifndef LINALG_AABB_H
#define LINALG_AABB_H


#include "../Math/Vector3.h"

class AABB {
public:
    AABB(const Vector3&min, const Vector3& max);
    bool operator==(const AABB &a) const;
    Vector3 max;
    Vector3 min;
};


#endif //LINALG_AABB_H
