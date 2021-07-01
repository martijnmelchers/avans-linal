#pragma once
#include <vector>
#include <SDL.h>
#include "../Math/Vector3.h"
#include "../Math/Line.h"

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
    void transform(const Matrix &m);
    void draw(SDL_Renderer* renderer);
    virtual void Update(double dt) = 0;
    Vector3 Center();
    Vector3 Up() const;
    Vector3 Down() const;
    Vector3 Left() const;
    Vector3 Right() const;
    Vector3 Forward() const;
};
