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
#include "windows.h"
#include "Objects/Camera.h"

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow ){

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
            "SDL2Test",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            600,
            600,
            0
    );

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    auto spaceShip = SpaceShip();
    auto camera = Camera(Vector3(0,0,0), Vector3(0,0,-1));

    bool active = true;
    SDL_Event sdlEvent;





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
                switch( sdlEvent.key.keysym.sym ){
                    case SDLK_LEFT:
                    {
                        auto m = Matrix::getTranslationMatrix(-0.001,0,0);
                        camera.eye.Transform(m);
                        camera.lookAt.Transform(m);
                        break;
                    }


                    case SDLK_RIGHT:{
                        auto m = Matrix::getTranslationMatrix(0.001,0,0);
                        camera.eye.Transform(m);
                        camera.lookAt.Transform(m);
                        break;
                    }

                    case SDLK_UP:{
                        auto m = Matrix::getTranslationMatrix(0,0.001,0);
                        camera.eye.Transform(m);
                        camera.lookAt.Transform(m);
                        break;
                    }

                    case SDLK_DOWN:{
                        auto m = Matrix::getTranslationMatrix(0,-0.001,0);
                        camera.eye.Transform(m);
                        camera.lookAt.Transform(m);
                        break;
                    }

                    case SDLK_q:{
                        auto m = Matrix::getRotationMatrix(camera.up, camera.eye, 0.01);
                        camera.lookAt.Transform(m);
                        break;
                    }


                    case SDLK_e:{
                        auto m = Matrix::getRotationMatrix(camera.up, camera.eye, -0.01);
                        camera.lookAt.Transform(m);
                        break;
                    }

                    case SDLK_0:{
                        auto m = Matrix::getTranslationMatrix(0,0,0.001);
                        camera.eye.Transform(m);
                        break;
                    }

                    case SDLK_1:{
                        auto m = Matrix::getTranslationMatrix(0,0,-0.001);
                        camera.eye.Transform(m);
                        break;
                    }

                    default:
                        break;
                }
            default:
                break;
        }


        Sleep(10);


        auto matrix = camera.getCameraTMatrix();

        spaceShip.transform(matrix);


        spaceShip.draw(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


