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
#include "Objects/Enemy.h"


int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow ){

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
            "Sascha & Martijn UNREAL ENGINE",
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
    auto enemy = Enemy();

    std::vector<Transform*> objects = {&spaceShip, &enemy};

    bool active = true;
    SDL_Event sdlEvent;

    auto camera = Camera(Vector3(0,0,0), Vector3(0,0,-1));

    Matrix cameraMatrixMan = Matrix();

    UINT NOW = SDL_GetPerformanceCounter();
    UINT LAST = 0;
    double deltaTime = 0;
    while(active){
        SDL_SetRenderDrawColor(renderer, 0,0 , 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        bool inputEnabled = false;
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();
        deltaTime = ((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency() );

        while (SDL_PollEvent(&sdlEvent)) {


            //TODO: Move controls
            switch (sdlEvent.type)
            {
                case SDL_QUIT:
                    active = false;
                    break;

                case SDL_KEYDOWN:
                    switch( sdlEvent.key.keysym.sym ){
                        case SDLK_LEFT:
                        {
                            cameraMatrixMan = Matrix::getTranslationMatrix(1,0,0);
                            inputEnabled = true;
                            break;
                        }


                        case SDLK_RIGHT:{
                            cameraMatrixMan = Matrix::getTranslationMatrix(-1,0,0);
                            inputEnabled = true;
                            break;
                        }

                        case SDLK_UP:{
                            cameraMatrixMan = Matrix::getTranslationMatrix(0,0,-1);
                            inputEnabled = true;
                            break;
                        }

                        case SDLK_DOWN:{
                            cameraMatrixMan = Matrix::getTranslationMatrix(0,0,1);
                            inputEnabled = true;
                            break;
                        }

                        case SDLK_PAGEUP:{
                            cameraMatrixMan = Matrix::getTranslationMatrix(0,-1,0);
                            inputEnabled = true;
                            break;
                        }


                        case SDLK_DELETE:{
                            std::cout << camera.eye.x << ", " << camera.eye.y << ", " << camera.eye.z << std::endl;
                            std::cout << camera.lookAt.x << ", " << camera.lookAt.y << ", " << camera.lookAt.z << std::endl;
                            break;
                        }

                        case SDLK_PAGEDOWN:{
                            camera.lookAt.y += 0.001;
                            camera.eye.y+= 0.001;
                            inputEnabled = true;
                            break;
                        }


                        case SDLK_LSHIFT:{
                            auto m = Matrix::getTranslationMatrix(0,0,-1);
                            spaceShip.transform(m);
                            break;
                        }

                        case SDLK_q:{

                            auto axis =Vector3(0,0,1);
                            auto center = spaceShip.Center();
                            auto m = Matrix::getRotationMatrix(axis,center, 2);
                            spaceShip.transform(m);
                            break;
                        }

                        case SDLK_e:{

                            auto axis =Vector3(0,0,-1);
                            auto center = spaceShip.Center();
                            auto m = Matrix::getRotationMatrix(axis,center, 2);
                            spaceShip.transform(m);
                            break;
                        }


                        case SDLK_w:{

                            auto axis =Vector3(1,0,0);
                            auto center = spaceShip.Center();
                            auto m = Matrix::getRotationMatrix(axis,center, 2);
                            spaceShip.transform(m);
                            break;
                        }

                        case SDLK_s:{
                            auto axis =Vector3(-1,0,0);
                            auto center = spaceShip.Center();
                            auto m = Matrix::getRotationMatrix(axis,center, 2);
                            spaceShip.transform(m);
                            break;
                        }

                        case SDLK_a:{

                            auto axis =Vector3(0,1,0);
                            auto center = spaceShip.Center();
                            auto m = Matrix::getRotationMatrix(axis,center, 2);
                            spaceShip.transform(m);
                            break;
                        }

                        case SDLK_d:{

                            auto axis =Vector3(0,-1,0);
                            auto center = spaceShip.Center();
                            auto m = Matrix::getRotationMatrix(axis,center, 2);
                            spaceShip.transform(m);
                            break;
                        }

                        default:
                            break;
                    }
                default:
                    break;
            }
        }


        //TODO: Generate sinewave and scale enemy to it.




        //Weird hack, but it werks.
        if(inputEnabled){
            camera.eye = Vector3(0,0,0);
            camera.lookAt = Vector3(0,0,-1);
            camera.eye.Transform(cameraMatrixMan);
            camera.lookAt.Transform(cameraMatrixMan);
        }

        for(auto* transform : objects){
            if(inputEnabled){
                transform->transform(camera.getCameraTMatrix());
            }

            transform->Update(deltaTime);
            transform->draw(renderer);
        }
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


