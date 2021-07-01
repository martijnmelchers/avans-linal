#include "Transform.h"
#include <SDL.h>
#include <cmath>

void Transform::transform(const Matrix &m) {
    for (auto &vert : verts) {
        vert.Transform(m);
    }
}

void Transform::draw(SDL_Renderer *renderer) {
    int nulpuntCanvasX = 600 / 2;
    int nulpuntCanvasY = 600 / 2;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    double near = 0.1;
    double far = 100.0;
    double fovY = -120;



    double scale = tan(fovY * 0.5 * M_PI / 180) * near;

    for (auto &line: lines) {
        auto perspective = Matrix::getPerspectiveMatrix(far, near, scale);

        auto startP = line.start.GetPerspective(perspective);
        auto endP = line.end.GetPerspective(perspective);

        SDL_RenderDrawPoint(renderer, Center().GetPerspective(perspective).x, Center().GetPerspective(perspective).y);

        if ((startP.w) > 0 && (endP.w > 0)) {

            int startX = int((startP.x) / startP.w * nulpuntCanvasX);
            int startY = int((startP.y) / startP.w * nulpuntCanvasY);
            int endX = int((endP.x) / endP.w * nulpuntCanvasX);
            int endY = int((endP.y) / endP.w * nulpuntCanvasY);

            SDL_RenderDrawLine(renderer, nulpuntCanvasX + startX, nulpuntCanvasY - startY, nulpuntCanvasX + endX,
                               nulpuntCanvasY - endY);
        }
    }
}

Vector3 Transform::Up() const {
    return Vector3(up->start.x - up->end.x, up->start.y - up->end.y, up->start.z - up->end.z);
}

Vector3 Transform::Center() const {
    double totalX= 0, totalY = 0, totalZ = 0;
    for (auto &point : verts) {
        totalX += point.x;
        totalY += point.y;
        totalZ += point.z;
    }

    auto size = (double) verts.size();
    Vector3 center = Vector3(totalX / size, totalY / size, totalZ / size);

    return center;
}

Vector3 Transform::Forward() const {
    auto diff = forward->end - forward->start;
    diff.Normalize();
    return diff;
}

Transform::~Transform() {
    left = nullptr;
    right = nullptr;
    up = nullptr;
    down = nullptr;
    forward = nullptr;
}


AABB Transform::GetAABB() const {
    auto min = Vector3(0,0,0);
    auto max = Vector3(0,0,0);

    for(auto& vert : verts){
        if(vert.x < min.x) min.x = vert.x;
        if(vert.y < min.y) min.y = vert.y;
        if(vert.z < min.z) min.z = vert.z;

        if(vert.x > max.x) max.x = vert.x;
        if(vert.y > max.y) max.y = vert.y;
        if(vert.z > max.z) max.z = vert.z;
    }

    auto box = AABB(min,max);
    return box;
}

bool Transform::Collides(const AABB& a, const AABB& b) {
    int meetingAxis = 0; //

    if ( (b.min.x > a.min.x) && (b.min.x < a.max.x) ) meetingAxis++;
    if ( (b.min.y > a.min.y) && (b.min.y < a.max.y) ) meetingAxis++;
    if ( (b.min.z > a.min.z) && (b.min.z < a.max.z) ) meetingAxis++;

    return meetingAxis >= 3;
}

Transform::Transform() {

}




