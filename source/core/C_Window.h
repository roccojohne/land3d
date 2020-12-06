#pragma once

#include "../main.h"

class C_Game;
class C_Window
{
    private:
       sf::Window *window;


    public:
    C_Window(C_Game &game);
    ~C_Window();
    sf::Window *GetRenderWindow(){ return window; };

    void render(C_Game &game);
};