#ifndef GAME_HPP
#define GAME_HPP

#include "SDL.h"

#include <iostream>
#include <conio.h>
#include <ctime>
#include <fstream>
#include <list>
#include <iterator>
#include <cmath>
#include <windows.h>

class Game {

public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();
    void upgrade();

    bool running() {return isRunning;}

private:

    //Mouse settings for detect
    bool mouseDown = false;
    bool mousePressed = false;
    bool mouseRightDown = false;
    bool mouseRightPressed = false;

    //Renderer settings
    int rNumber = 0;
    int gNumber = 0;
    int bNumber = 255;

    //Cookies settings
    int cookiies = 0;
    int upclic = 0;
    int upclicPrice = 0;

    //Game settings
    int cnt = 0;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif // GAME_HPP
