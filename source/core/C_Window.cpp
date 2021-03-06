#include "C_Window.h"
#include <gl/glew.h>



C_Window::C_Window(C_Game &game)
{
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 1;
    settings.majorVersion = 4;
    settings.minorVersion = 6;
    settings.attributeFlags = sf::ContextSettings::Core; //settings.Core;


    window = new sf::/*Render*/Window(sf::VideoMode(800, 600),  "Hello World", sf::Style::Default, settings);
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

};