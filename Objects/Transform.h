//
// Created by sasch on 23/06/2021.
//
#pragma once
#include <vector>
#include <SDL.h>
#include "../Math/Vector3.h"
#include "../Math/Line.h"

class Transform {
protected:
    std::vector<Vector3> verts;
    std::vector<Line> lines;
    Line* up;
    Line* down;
    Line* left;
    Line* right;
public:
    Transform();
    void transform(const Matrix &m);
    void draw(SDL_Renderer* renderer);
    virtual void Update(double dt) = 0;
    Vector3 Center();
    Vector3 Up() const;
};
