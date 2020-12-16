#pragma once

#include "../main.h"

class C_Game;
class C_Window
{
    private:
       sf::RenderWindow *window;


    public:
    C_Window(C_Game &game);
    ~C_Window();
    sf::RenderWindow *GetRenderWindow(){ return window; };

    void render(C_Game &game);
};