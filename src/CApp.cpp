#include "CApp.h"
#include <iostream>
using namespace std;

void CApp::start() {
    leftPaddle.y = (HEIGHT/2)-(leftPaddle.h/2);
    rightPaddle.y = (HEIGHT/2)-(leftPaddle.h/2);

    if(turn) {
        ball.x = leftPaddle.x + (leftPaddle.w * 4);
        velX = BALL_SPEED/2;
    } else {
        ball.x = rightPaddle.x - (rightPaddle.w * 4);
        velX =- BALL_SPEED/2;
    }

    velY =0 ;
    ball.y = HEIGHT/2 - (SIZE/2);
    turn = !turn;
}

void CApp::update() {
    if(SDL_HasIntersection(&ball, &rightPaddle)) {
        double rel = (rightPaddle.y + (rightPaddle.h/2)) - (ball.y+(SIZE/2));
        double norm = rel / (rightPaddle.h/2);
        double bounce = norm * (5 * PI/12);
        velX = -BALL_SPEED * cos(bounce);
        velY = BALL_SPEED * -sin(bounce);
    }

    if(SDL_HasIntersection(&ball, &leftPaddle)) {
        double rel = (leftPaddle.y + (leftPaddle.h/2)) - (ball.y + (SIZE/2));
        double norm = rel / (leftPaddle.h/2);
        double bounce = norm * (5 * PI/12);
        velX=BALL_SPEED * cos(bounce);
        velY=BALL_SPEED * -sin(bounce);
    }

    if(ball.y > rightPaddle.y + (rightPaddle.h/2)) rightPaddle.y += SPEED;
    if(ball.y < rightPaddle.y + (rightPaddle.h/2)) rightPaddle.y -= SPEED;

    if(ball.x <= 0) {
        start();
        }

    if(ball.x + SIZE >= WIDTH) {
        start();
        }

    if(ball.y <= 0 || ball.y + SIZE >= HEIGHT) {
        velY=-velY;
    }

    ball.x += velX;
    ball.y += velY;

    if(leftPaddle.y<0) {
        leftPaddle.y = 0;
    }

    if(leftPaddle.y + leftPaddle.h > HEIGHT) {
        leftPaddle.y = HEIGHT - leftPaddle.h;
    }

    if(rightPaddle.y<0) {
        rightPaddle.y = 0;
    }
    
    if(rightPaddle.y + rightPaddle.h > HEIGHT) {
        rightPaddle.y = HEIGHT - rightPaddle.h;
    }
}

void CApp::event() {
    SDL_Event e;

    const Uint8 * keystates = SDL_GetKeyboardState(NULL);

    while(SDL_PollEvent(&e))  {
        if(e.type == SDL_QUIT) {
            running = false;
        } 
    }

    if(keystates[SDL_SCANCODE_ESCAPE]) {
        running = false;
    } 

    if(keystates[SDL_SCANCODE_UP]) {
        leftPaddle.y -= SPEED;
    }

    if(keystates[SDL_SCANCODE_DOWN]) {
        leftPaddle.y += SPEED;
    } 
}

void CApp::render() {
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255);
    SDL_RenderClear(renderer);

    frameCount++;
    timerFPS = SDL_GetTicks()-lastFrame;

    if(timerFPS<(1000/60)) {
        SDL_Delay((1000/60)-timerFPS);
    }

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
    SDL_RenderFillRect(renderer, &leftPaddle);
    SDL_RenderFillRect(renderer, &rightPaddle);
    SDL_RenderFillRect(renderer, &ball);
    SDL_RenderPresent(renderer);
}

void CApp::init() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) std::cout << "Failed at SDL_Init()" << std::endl;
    if(SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0) std::cout << "Failed at SDL_CreateWindowAndRenderer())" << std::endl;
    running = 1;
    lastTime = 0;

    color.r=color.g=color.b=255;
    leftPaddle.x = 32; 
    leftPaddle.h = HEIGHT/4;
    leftPaddle.y=(HEIGHT/2) - (leftPaddle.h/2);
    leftPaddle.w=12;

    rightPaddle=leftPaddle;
    rightPaddle.x = WIDTH - rightPaddle.w - 32;
    ball.w = ball.h = SIZE;

    start();
}