#include "CApp.h"
#include "helpers.h"
using namespace std;
 
bool CApp::OnInit() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0 ){
        cout << SDL_GetError() << endl;
        return false;
    }

    window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

    if (window == NULL){
        cout << SDL_GetError() << endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    SDL_RenderClear(renderer);

    SDL_Rect player;
    player.x = 50;
    player.y = 50;
    player.w = 50;
    player.h = 50;

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    SDL_RenderFillRect(renderer, &player);

    SDL_RenderPresent(renderer);

    return true;
}