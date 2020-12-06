#include "C_Game.h"

C_Game::C_Game()
{
    spdlog::info("init game");

    setting = new C_Setting();
    mainwindow = new C_Window(*this);
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
        }

        glClearColor(.33f, .33f, .33f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        mainwindow->render(*this);
        
        mainwindow->GetRenderWindow()->display();
    }
    return false;
}
