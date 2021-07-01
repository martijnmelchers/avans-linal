#pragma once
#include <vector>
#include <SDL.h>
#include "../Math/Vector3.h"
#include "../Math/Line.h"
#include "AABB.h"


class Transform {
protected:
    std::vector<Vector3> verts;
    std::vector<Line> lines;
    Line* up{};
    Line* down{};
    Line* left{};
    Line* right{};
    Line* forward{};
public:
    Transform();
    virtual ~Transform();
    void transform(const Matrix &m);
    void draw(SDL_Renderer* renderer);
    virtual void Update(double dt) = 0;
    virtual void Collide(Transform* collider) = 0;
    AABB GetAABB() const;
    Vector3 Center() const;
    Vector3 Up() const;
    Vector3 Down() const;
    Vector3 Left() const;
    Vector3 Right() const;
    Vector3 Forward() const;
    static bool Collides(const AABB& a, const AABB& b);
    bool flagDestroy = false;
};
