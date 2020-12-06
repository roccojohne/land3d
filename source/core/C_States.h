#pragma once

#include "../main.h"

class C_States
{
    public:
    virtual void events(C_Game &game, sf::Event &event) = 0;
    virtual void update(C_Game &game, double &frametime) = 0;
    virtual void render(C_Game &game) = 0;
};

class C_States_Play : public C_States 
{
    public:
    virtual void events(C_Game &game, sf::Event &event) = 0;
    virtual void update(C_Game &game, double &frametime) = 0;
    virtual void render(C_Game &game) = 0;
};

