#include "AABB.h"

AABB::AABB(const Vector3& min, const Vector3& max): min(min), max(max) {

}

bool AABB::operator==(const AABB &a) const {
    return min == a.min && max == a.max;
}
