#include <SDL2/SDL.h>
#include <iostream>
#include "CApp.h"

int main() {
 CApp app;
 
    app.init();

 while(app.running) {
    app.lastFrame = SDL_GetTicks();

    if(app.lastFrame >= (app.lastTime + 1000)) {
        app.lastTime = app.lastFrame;
        app.fps = app.frameCount;
        app.frameCount = 0;
    }

    app.update();
    app.event();
    app.render();
}

    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
    SDL_Quit();
}