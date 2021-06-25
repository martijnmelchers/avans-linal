//
// Created by sasch on 23/06/2021.
//

#include "Transform.h"
#include <SDL.h>
#include <cmath>

void Transform::transform(Matrix &m) {
    for(auto & vert : verts){
        vert.Transform(m);
    }
}

Transform::Transform() {

}

void Transform::draw(SDL_Renderer* renderer) {
    int nulpuntCanvasX = 600/2;
    int nulpuntCanvasY = 600/2;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    double near = 0.1;
    double far = 10000.0;
    double fovY = 3;
    double scale = near * tan(fovY*0.5);



    for(auto& line: lines){
        auto perspective = Matrix::getPerspectiveMatrix(far, near, scale);

        auto startP = line.start.GetPerspective(perspective);
        auto endP = line.end.GetPerspective(perspective);

        if((startP.w) > 0 && (endP.w > 0)){
            int startX = int(startP.x/startP.w*600/startP.w);
            int startY = int(startP.y/startP.w*600/startP.w);
            int endX = int(endP.x/endP.w*600/endP.w);
            int endY = int(endP.y/endP.w*600/endP.w);

            SDL_RenderDrawLine(renderer, nulpuntCanvasX + startX, nulpuntCanvasY - startY, nulpuntCanvasX + endX, nulpuntCanvasY - endY);
        }
    }
}

Vector3 Transform::Up() const {
    return Vector3(up->start.x - up->end.x, up->start.y - up->end.y, up->start.z - up->end.z);
}

Vector3 Transform::Center() {
    double totalX, totalY, totalZ;
    for(auto& point : verts){
        totalX += point.x;
        totalY += point.y;
        totalZ += point.z;
    }

    Vector3 center = Vector3(totalX/verts.size(), totalY/verts.size(), totalZ/verts.size());

    return center;
}


