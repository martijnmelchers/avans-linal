#include <iostream>
#include <SDL.h>
#include <SDL_render.h>
#include <SDL_video.h>
#include <SDL_main.h>

#define SDL_MAIN_HANDLED

#include <windows.h>
#include <vector>
#include "Math/Vector3.h"
#include "Math/Line.h"
#include "Objects/SpaceShip.h"
#include "Objects/Camera.h"
#include "Objects/Enemy.h"
#include "Objects/Bullet.h"


int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow) {

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
            "Sascha & Martijn UNREAL ENGINE",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            1000,
            1000,
            0
    );

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    auto spaceShip = SpaceShip();
    auto enemy = Enemy();
    std::vector<Transform *> objects = {&spaceShip, &enemy};

    bool active = true;
    SDL_Event sdlEvent;

    auto camera = Camera(Vector3(0, 0, 0), Vector3(0, 0, -1));

    UINT NOW = SDL_GetPerformanceCounter();
    UINT LAST = 0;

    double deltaTime = 0;
    while (active) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        bool transformWorld = false;
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();
        deltaTime = ((NOW - LAST) * 1000 / (double) SDL_GetPerformanceFrequency());

        auto cameraMatrixMan = Matrix::getOneMatrix();
        while (SDL_PollEvent(&sdlEvent)) {
            //TODO: Move controls
            switch (sdlEvent.type) {

                case SDL_QUIT:
                    active = false;
                    break;

                case SDL_KEYDOWN:
                    std::cout << sdlEvent.key.keysym.sym << std::endl;
                    switch (sdlEvent.key.keysym.sym) {
                        case SDLK_LEFT: {
                            cameraMatrixMan = Matrix::getTranslationMatrix(1, 0, 0);
                            transformWorld = true;
                            break;
                        }

                        case SDLK_RIGHT: {
                            cameraMatrixMan = Matrix::getTranslationMatrix(-1, 0, 0);
                            transformWorld = true;
                            break;
                        }

                        case SDLK_UP: {
                            cameraMatrixMan = Matrix::getTranslationMatrix(0, 0, -1);
                            transformWorld = true;
                            break;
                        }

                        case SDLK_DOWN: {
                            cameraMatrixMan = Matrix::getTranslationMatrix(0, 0, 1);
                            transformWorld = true;
                            break;
                        }

                        case SDLK_PAGEUP: {
                            cameraMatrixMan = Matrix::getTranslationMatrix(0, -1, 0);
                            transformWorld = true;
                            break;
                        }


                        case SDLK_DELETE: {
                            std::cout << camera.eye.x << ", " << camera.eye.y << ", " << camera.eye.z << std::endl;
                            std::cout << camera.lookAt.x << ", " << camera.lookAt.y << ", " << camera.lookAt.z
                                      << std::endl;
                            break;
                        }

                        case SDLK_PAGEDOWN: {
                            cameraMatrixMan = Matrix::getTranslationMatrix(0, 1, 0);
                            transformWorld = true;
                            break;
                        }


                        case SDLK_LSHIFT: {
                            auto axis = spaceShip.Forward();
                            auto m = Matrix::getTranslationMatrix(axis.x, axis.y, axis.z);
                            spaceShip.transform(m);
                            break;
                        }

                        case SDLK_q: {

                            auto axis = Vector3(0, 0, 1);
                            auto center = spaceShip.Center();
                            auto m = Matrix::getRotationMatrix(axis, center, 2);
                            spaceShip.transform(m);
                            break;
                        }

                        case SDLK_e: {

                            auto axis = Vector3(0, 0, -1);
                            auto center = spaceShip.Center();
                            auto m = Matrix::getRotationMatrix(axis, center, 2);
                            spaceShip.transform(m);
                            break;
                        }

                        case SDLK_w: {

                            auto axis = Vector3(1, 0, 0);
                            auto center = spaceShip.Center();
                            auto m = Matrix::getRotationMatrix(axis, center, 2);
                            spaceShip.transform(m);
                            break;
                        }

                        case SDLK_s: {
                            auto axis = Vector3(-1, 0, 0);
                            auto center = spaceShip.Center();
                            auto m = Matrix::getRotationMatrix(axis, center, 2);
                            spaceShip.transform(m);
                            break;
                        }

                        case SDLK_a: {

                            auto axis = Vector3(0, 1, 0);
                            auto center = spaceShip.Center();
                            auto m = Matrix::getRotationMatrix(axis, center, 2);
                            spaceShip.transform(m);
                            break;
                        }
                        case SDLK_0: {
                            auto *bullet = new Bullet(spaceShip.Center(), spaceShip.Forward(), enemy);
                            objects.emplace_back(bullet);
                            break;
                        }

                        case SDLK_d: {

                            auto axis = Vector3(0, -1, 0);
                            auto center = spaceShip.Center();
                            auto m = Matrix::getRotationMatrix(axis, center, 2);
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

        //Weird hack, but it werks.



        if (transformWorld) {
            camera.eye = Vector3(0, 0, 0);
            camera.lookAt = Vector3(0, 0, -1);
            camera.eye.Transform(cameraMatrixMan);
            camera.lookAt.Transform(cameraMatrixMan);
        }


        for (auto it = objects.begin(); it != objects.end();) {
            Transform *transform = *it;


            if (transformWorld) {
                transform->transform(camera.GetCameraTMatrix());
            }

            transform->Update(deltaTime);
            for (auto *collider : objects) {
                if (collider != transform) {
                    bool collides = Transform::Collides(transform->GetAABB(), collider->GetAABB());
                    if (collides) {
                        transform->Collide(collider);
                        collider->Collide(transform);
                    }
                }
            }

            transform->draw(renderer);

            if (transform->flagDestroy) {
                if (dynamic_cast<SpaceShip *>(transform) == nullptr) {
                    it = objects.erase(it);
                } else {
                    active = true;
                }
            } else {
                it++;
            }
        }

        SDL_RenderPresent(renderer);
    }

    for (Transform *transform : objects) {
        delete transform;
    }
    objects.clear();
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


