#include <iostream>
#include <SDL.h>
#include <SDL_render.h>
#include <SDL_video.h>
#include <SDL_main.h>
#define SDL_MAIN_HANDLED
#include <windows.h>
#include <array>
#include <vector>
#include "Math/Vector3.h"
#include "Math/Line.h"
#include "Math/Matrix.h"


int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow ){

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
            "SDL2Test",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            800,
            800,
            0
    );

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    std::vector<Vector3> points;


    // Cube from example.
    points.emplace_back(Vector3(10, 10, -50));
    points.emplace_back(Vector3(10, 10, -70));
    points.emplace_back(Vector3(-10, 10,-70));
    points.emplace_back(Vector3(-10, 10,-50));

    points.emplace_back(Vector3(10, -10, -50));
    points.emplace_back(Vector3(10, -10, -70));
    points.emplace_back(Vector3(-10, -10, -70));
    points.emplace_back(Vector3(-10, -10, -50));



    std::vector<Line> lines;


    bool active = true;
    SDL_Event sdlEvent;
    auto matrix = Matrix::getRotationMatrixY(-45);

    for(auto& point : points){
        point.Transform(matrix);
    }


    lines.emplace_back(Line(points[0], points[1]));
    lines.emplace_back(Line(points[1], points[2]));
    lines.emplace_back(Line(points[2], points[3]));
    lines.emplace_back(Line(points[3], points[0]));
    lines.emplace_back(Line(points[0], points[4]));
    lines.emplace_back(Line(points[1], points[5]));
    lines.emplace_back(Line(points[2], points[6]));
    lines.emplace_back(Line(points[3], points[7]));
    lines.emplace_back(Line(points[4], points[5]));
    lines.emplace_back(Line(points[5], points[6]));
    lines.emplace_back(Line(points[6], points[7]));
    lines.emplace_back(Line(points[7], points[4]));

    while(active){
        SDL_PollEvent(&sdlEvent);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        switch (sdlEvent.type)
        {
            case SDL_QUIT:
                active = false;
                break;
            case SDL_KEYDOWN:
                printf("Key down!\n");
                break;
            default:
                break;
        }


        int nulpuntCanvasX = 800/2;
        int nulpuntCanvasY = 800/2;

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


        SDL_RenderPresent(renderer);
    }



    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


