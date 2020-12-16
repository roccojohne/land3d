#include "C_Window.h"
#include <gl/glew.h>



C_Window::C_Window(C_Game &game)
{
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 0;
    settings.Debug;


    window = new sf::RenderWindow(sf::VideoMode(800, 600),  "Hello World", sf::Style::Default, settings);
    if (!window)
    {
        spdlog::error("Can't create the mainwindow");
        exit(-1);
    }
    spdlog::info("Window successfull created");
    window->setVerticalSyncEnabled(true);

    glewExperimental = GL_TRUE;
    auto err = glewInit();
    if (err != GLEW_OK)
    {
        spdlog::error(glewGetErrorString(err));
        exit(-1);
    }
    spdlog::info("OPENGL-INFO**********************************************");
    spdlog::info("using GLEW      {}", glewGetString(GLEW_VERSION));
    spdlog::info("Opengl Version  {}", glGetString(GL_VERSION));
    spdlog::info("Opengl Vendor   {}", glGetString(GL_VENDOR));
    spdlog::info("Opengl Renderer {}", glGetString(GL_RENDERER));
    spdlog::info("END******************************************************");

};

C_Window::~C_Window()
{
};

void C_Window::render(C_Game &game)
{

    int pos = 0;
    glBegin(GL_TRIANGLES);
        glColor3f(.9f, .1f, .9f);
        glVertex2f(.0f, -.5f);
        glColor3f(.1f, .9f, .9f);
        glVertex2f(-.5f, .5f);
        glColor3f(.9f, .9f, .1f);
        glVertex2f(.5f, .5f);
    glEnd();
};