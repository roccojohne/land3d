#pragma once

#include "../main.h"

class C_States
{
    public:
    virtual void events(C_Game &game, sf::Event &event) = 0;
    virtual void update(C_Game &game, double frametime) = 0;
    virtual void render(C_Game &game) = 0;
};


class C_States_Play : public C_States
{
public:
    C_States_Play(C_Game &game);
    ~C_States_Play();
    void events(C_Game& game, sf::Event& event);
    void update(C_Game& game, double frametime);
    void render(C_Game& game);
};

class C_States_Menu : public C_States                                   // the mainmenu
{
    private:
        sf::Text *beenden = nullptr;
        sf::Text *settings = nullptr;
        sf::Text *neu = nullptr;
        sf::Text *laden = nullptr;
        sf::Text *speichern = nullptr;
        sf::Text *credits = nullptr;

        std::list<sf::Text *>menulist;

    public:
        C_States_Menu(C_Game &game);
        ~C_States_Menu();
        void events(C_Game& game, sf::Event& event);
        void update(C_Game& game, double frametime);
        void render(C_Game& game);
};

class C_States_Settings : public C_States
{
public:
    virtual void events(C_Game& game, sf::Event& event) = 0;
    virtual void update(C_Game& game, double& frametime) = 0;
    virtual void render(C_Game& game) = 0;
};

class C_States_Credits : public C_States
{
public:
    virtual void events(C_Game& game, sf::Event& event) = 0;
    virtual void update(C_Game& game, double& frametime) = 0;
    virtual void render(C_Game& game) = 0;
};

