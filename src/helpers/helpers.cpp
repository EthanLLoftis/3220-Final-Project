#include "helpers.h"

SDL_Surface* loadPlayer(char const *file) {
    SDL_Surface* image_surface = SDL_LoadBMP(file);

    if(!image_surface) {
        return nullptr;
    }

    return image_surface;
};