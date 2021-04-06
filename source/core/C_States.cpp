#include  "C_States.h"



#define GLCHECK() printOglError(__LINE__)

int printOglError(int line)
{

    GLenum glErr;
    int    retCode = 0;

    glErr = glGetError();
    if (glErr != GL_NO_ERROR)
    {
        printf("glError in file  @ line %d: %s\n", line, gluErrorString(glErr));
        retCode = 1;
    }
    return retCode;
}



/*
*
*   menustate for the mainmenu
*
*/

C_States_Menu::C_States_Menu(C_Game& game)
{
    spdlog::info("creating menu text");
    int charsize = int(game.GetWindow()->GetRenderWindow()->getSize().y / 20);

    auto first = (game.GetWindow()->GetRenderWindow()->getSize().y / 2) - (3 * charsize);
    
    neu = new sf::Text("New", *game.GetSetting()->GetFont());
    neu->setFillColor(sf::Color(130, 130, 130, 255));
    neu->setPosition(150.f, float(first));
    neu->setCharacterSize(charsize);
    laden = new sf::Text("Load", *game.GetSetting()->GetFont());
    laden->setFillColor(sf::Color(130, 130, 130, 255));
    laden->setPosition(150.f, float(first += charsize));
    laden->setCharacterSize(charsize);
    speichern = new sf::Text("Save", *game.GetSetting()->GetFont());
    speichern->setFillColor(sf::Color(130, 130, 130, 255));
    speichern->setPosition(150.f, float(first += charsize));
    speichern->setCharacterSize(charsize);
    settings = new sf::Text("Optionen", *game.GetSetting()->GetFont());
    settings->setFillColor(sf::Color(130, 130, 130, 255));
    settings->setPosition(150.f, float(first += charsize));
    settings->setCharacterSize(charsize);
    credits = new sf::Text("Credits", *game.GetSetting()->GetFont());
    credits->setFillColor(sf::Color(130, 130, 130, 255));
    credits->setPosition(150.f, float(first += charsize));
    credits->setCharacterSize(charsize);
    beenden = new sf::Text("Exit", *game.GetSetting()->GetFont());
    beenden->setFillColor(sf::Color(130, 130, 130, 255));
    beenden->setPosition(150.f, float(first += charsize));
    beenden->setCharacterSize(charsize);

    menulist.push_back(neu);
    menulist.push_back(laden);
    menulist.push_back(speichern);
    menulist.push_back(settings);
    menulist.push_back(credits);
    menulist.push_back(beenden);
};

C_States_Menu::~C_States_Menu()
{

};

void C_States_Menu::events(C_Game& game, sf::Event& event)
{
    for (auto item : menulist)
    {
        if (item->getGlobalBounds().contains((sf::Vector2f(sf::Mouse::getPosition(*game.GetWindow()->GetRenderWindow()))))) // check if mouse over item
        {
            item->setFillColor(sf::Color(170, 170, 170, 255));
            item->setLetterSpacing(6.f);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                spdlog::warn(std::string(item->getString()));
                if (item->getString() == std::string("Exit"))
                    game.GetWindow()->GetRenderWindow()->close();
                if (item->getString() == std::string("New"))
                    game.changeCurrentState(game.ID_STATES_PLAY);
            }
        }
        else 
        {
            item->setFillColor(sf::Color(130, 130, 130, 255));
            item->setLetterSpacing(1.f);
        }

    }
};

void C_States_Menu::update(C_Game& game, double frametime)
{

};

void C_States_Menu::render(C_Game& game)
{
    glClearColor(.30f, .30f, .30f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);

 //   for (auto item : menulist)
        //game.GetWindow()->GetRenderWindow()->draw(*item);
};


/*
*
*
*   playstate
*
*/

C_States_Play::C_States_Play(C_Game& game)
{
    spdlog::info("render state init doen\n");

    //auto *shader = new C_Shader(game, "data\\shaders\\default_vs.glsl", "data\\shaders\\default_fs.glsl");
    terrain = new C_Terrain(game);
 };

C_States_Play::~C_States_Play()
{
    //delete testobjekt;
};

void C_States_Play::events(C_Game& game, sf::Event& event)
{

};


void C_States_Play::update(C_Game& game, double frametime)
{
    //spdlog::info("Frametime : ", "%d", frametime);
};

float ax = 10.0;
float ay = 30.0;

void C_States_Play::render(C_Game& game)
{
    glClearColor(.3f, .3f, .3f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);

    terrain->render(game);
 
};
