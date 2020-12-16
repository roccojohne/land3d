#include "C_Game.h"

C_Game::C_Game()
{
    spdlog::info("init game");

    setting = new C_Setting();
    mainwindow = new C_Window(*this);
    rendertimer = new sf::Clock;
    changeCurrentState(ID_STATES_MENU);
}

C_Game::~C_Game()
{
    spdlog::info("exit game");
}

bool C_Game::run()
{
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event *event = new sf::Event;

    while (mainwindow->GetRenderWindow()->isOpen())
    {

        while (mainwindow->GetRenderWindow()->pollEvent(*event))
        {
            // "close requested" event: we close the window
            if (event->type == sf::Event::Closed)
                mainwindow->GetRenderWindow()->close();
        
            currentstate->events(*this, *event);

        }

        currentstate->update(*this, rendertimer->restart().asSeconds());

        glClear(GL_COLOR_BUFFER_BIT);

        currentstate->render(*this);

//        glClearColor(.33f, .33f, .33f, 1.0f);
  
        mainwindow->render(*this);
        
        mainwindow->GetRenderWindow()->display();
    }
    return false;
}

void C_Game::changeCurrentState(const int state_id)
{
    if (currentstate)
        delete currentstate;

    switch (state_id)
    {
        case ID_STATES_MENU:
        {
            spdlog::info("renderstate changed to mainmenu");
            currentstate = new C_States_Menu(*this);
        }
        break;
        default:
        {
            spdlog::error("UNKNOWN RENDERSTATE");
        }
    }
}
