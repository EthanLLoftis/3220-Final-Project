#ifndef _CAPP_H_
    #define _CAPP_H_
 
#include <SDL2/SDL.h>
#include <iostream>
 
class CApp {

    private:

        bool Running;

        SDL_Window* window;

        SDL_Surface* windowSurface;

        SDL_Renderer* renderer;

        SDL_Surface* playerSurface;

        SDL_Rect playerPosition;

        SDL_Surface** enemySurface;

        SDL_Rect enemyPosition[8];

        SDL_Texture* texture;

 
    public:
 
        CApp();
 
        int OnExecute();
    public:

        bool OnInit();
 
        void OnEvent(SDL_Event* Event);
 
        void OnLoop();
 
        void OnRender();
 
        void OnCleanup();
};

#endif