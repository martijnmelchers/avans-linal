#include "Transform.h"
#include <SDL.h>
#include <cmath>

void Transform::transform(const Matrix &m) {
    for (auto &vert : verts) {
        vert.Transform(m);
    }
}

Transform::Transform() = default;

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

Vector3 Transform::Center() {
    double totalX, totalY, totalZ;
    for (auto &point : verts) {
        totalX += point.x;
        totalY += point.y;
        totalZ += point.z;
    }

    auto size = (double) verts.size();
    Vector3 center = Vector3(totalX / size, totalY / size, totalZ / size);

    return center;
}


