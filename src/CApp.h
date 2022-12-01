#ifndef _CAPP_H_
    #define _CAPP_H_
 
#include <SDL2/SDL.h>
#include <iostream>

#define WIDTH 720
#define HEIGHT 720
#define BALL_SPEED 14
#define SPEED 9
#define SIZE 16
#define PI 3.14159265358979323846
 
class CApp {

    public:
        SDL_Renderer* renderer;
        SDL_Window* window;
        SDL_Color color;
        bool running;
        int frameCount, timerFPS, lastFrame, fps;

        int lastTime;

        SDL_Rect leftPaddle, rightPaddle, ball;
        float velX, velY;
        bool turn;

    public:
        void start();

        void update();

        void event();

        void render();

        void init();
};

#endif