#include "helpers.h"
#include "CApp.h"
#include <iostream>
using namespace std;

bool renderPlayer(SDL_Renderer* renderer, SDL_Window* window) {

    if (window == NULL){
        cout << SDL_GetError() << endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    SDL_RenderClear(renderer);

    SDL_Rect r;
    r.x = 50;
    r.y = 50;
    r.w = 50;
    r.h = 50;

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    SDL_RenderFillRect(renderer, &r);

    SDL_RenderPresent(renderer);

    return true;
};