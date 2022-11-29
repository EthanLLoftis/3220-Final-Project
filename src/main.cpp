#include <iostream>
#include <SDL2/SDL.h>


using namespace std;

int main() {

    if(SDL_Init(SDL_INIT_EVERYTHING) > 0) {
        cout << "sdl init failed with error: " << SDL_GetError() << endl;
        return EXIT_FAILURE;
    }
    
    cout << "SDL2 setup"<< endl;

    return EXIT_SUCCESS;
}