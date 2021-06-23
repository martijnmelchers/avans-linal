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
#include "Objects/SpaceShip.h"


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



    auto spaceShip = SpaceShip();




    bool active = true;
    SDL_Event sdlEvent;




    auto center = spaceShip.Center();
    auto up = Vector3(0,1,0);
    auto matrix = Matrix::getRotationMatrix(up, center, 75);
    spaceShip.transform(matrix);


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

        spaceShip.draw(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


