#include "C_Game.h"

void GLAPIENTRY
MessageCallback(GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar* message,
    const void* userParam);

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
        
        mainwindow->GetRenderWindow()->pushGLStates();
            currentstate->render(*this);
            mainwindow->render(*this);
        mainwindow->GetRenderWindow()->popGLStates();

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
        case ID_STATES_PLAY:
        {
            glEnable(GL_DEBUG_OUTPUT);
            glDebugMessageCallback(MessageCallback, 0);

            spdlog::info("randerstate changes to playstate");
            currentstate = new C_States_Play(*this);
        }
        break;
        default:
        {
            spdlog::error("UNKNOWN RENDERSTATE");
        }
    }
}


void GLAPIENTRY
MessageCallback(GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar* message,
    const void* userParam)
{
    // ignore non-significant error/warning codes
    if (id == 131169 || id == 131185 || id == 131218 || id == 131204) return;

    std::cout << "---------------" << std::endl;
    std::cout << "Debug message (" << id << "): " << message << std::endl;

    switch (source)
    {
    case GL_DEBUG_SOURCE_API:             std::cout << "Source: API"; break;
    case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   std::cout << "Source: Window System"; break;
    case GL_DEBUG_SOURCE_SHADER_COMPILER: std::cout << "Source: Shader Compiler"; break;
    case GL_DEBUG_SOURCE_THIRD_PARTY:     std::cout << "Source: Third Party"; break;
    case GL_DEBUG_SOURCE_APPLICATION:     std::cout << "Source: Application"; break;
    case GL_DEBUG_SOURCE_OTHER:           std::cout << "Source: Other"; break;
    } std::cout << std::endl;

    switch (type)
    {
    case GL_DEBUG_TYPE_ERROR:               std::cout << "Type: Error"; break;
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: std::cout << "Type: Deprecated Behaviour"; break;
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  std::cout << "Type: Undefined Behaviour"; break;
    case GL_DEBUG_TYPE_PORTABILITY:         std::cout << "Type: Portability"; break;
    case GL_DEBUG_TYPE_PERFORMANCE:         std::cout << "Type: Performance"; break;
    case GL_DEBUG_TYPE_MARKER:              std::cout << "Type: Marker"; break;
    case GL_DEBUG_TYPE_PUSH_GROUP:          std::cout << "Type: Push Group"; break;
    case GL_DEBUG_TYPE_POP_GROUP:           std::cout << "Type: Pop Group"; break;
    case GL_DEBUG_TYPE_OTHER:               std::cout << "Type: Other"; break;
    } std::cout << std::endl;

    switch (severity)
    {
    case GL_DEBUG_SEVERITY_HIGH:         std::cout << "Severity: high"; break;
    case GL_DEBUG_SEVERITY_MEDIUM:       std::cout << "Severity: medium"; break;
    case GL_DEBUG_SEVERITY_LOW:          std::cout << "Severity: low"; break;
    case GL_DEBUG_SEVERITY_NOTIFICATION: std::cout << "Severity: notification"; break;
    } std::cout << std::endl;
    std::cout << std::endl;
}