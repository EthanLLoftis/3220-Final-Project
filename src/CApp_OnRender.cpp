#include "CApp.h"
 
void CApp::OnRender() {
    SDL_BlitSurface(playerSurface, NULL, windowSurface, NULL);
}