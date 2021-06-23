//
// Created by sasch on 23/06/2021.
//

#include "Transform.h"
#include <SDL.h>
void Transform::transform(Matrix &m) {
    for(auto & vert : verts){
        vert.Transform(m);
    }
}

Transform::Transform() {

}

void Transform::draw(SDL_Renderer* renderer) {
    int nulpuntCanvasX = 800/2;
    int nulpuntCanvasY = 800/2;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    for(auto& line: lines){
        if(line.start.z < 0 && line.end.z < 0){
            int startX = line.start.x/-line.start.z*200;
            int startY = line.start.y/-line.start.z*200;
            int endX = line.end.x/-line.end.z*200;
            int endY = line.end.y/-line.end.z*200;

            SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
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


