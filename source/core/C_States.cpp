#include  "C_States.h"

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
    neu->setPosition(150, first);
    neu->setCharacterSize(charsize);
    laden = new sf::Text("Load", *game.GetSetting()->GetFont());
    laden->setFillColor(sf::Color(130, 130, 130, 255));
    laden->setPosition(150, first += charsize);
    laden->setCharacterSize(charsize);
    speichern = new sf::Text("Save", *game.GetSetting()->GetFont());
    speichern->setFillColor(sf::Color(130, 130, 130, 255));
    speichern->setPosition(150, first += charsize);
    speichern->setCharacterSize(charsize);
    settings = new sf::Text("Optionen", *game.GetSetting()->GetFont());
    settings->setFillColor(sf::Color(130, 130, 130, 255));
    settings->setPosition(150, first += charsize);
    settings->setCharacterSize(charsize);
    credits = new sf::Text("Credits", *game.GetSetting()->GetFont());
    credits->setFillColor(sf::Color(130, 130, 130, 255));
    credits->setPosition(150, first += charsize);
    credits->setCharacterSize(charsize);
    beenden = new sf::Text("Exit", *game.GetSetting()->GetFont());
    beenden->setFillColor(sf::Color(130, 130, 130, 255));
    beenden->setPosition(150, first += charsize);
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
        }
        else 
        {
            item->setFillColor(sf::Color(130, 130, 130, 255));
        }

    }
};

void C_States_Menu::update(C_Game& game, double frametime)
{

};

void C_States_Menu::render(C_Game& game)
{
    glClearColor(.30f, .30f, .30f, 1.f);
    game.GetWindow()->GetRenderWindow()->draw(*neu);
    game.GetWindow()->GetRenderWindow()->draw(*laden); 
    game.GetWindow()->GetRenderWindow()->draw(*speichern);
    game.GetWindow()->GetRenderWindow()->draw(*settings);
    game.GetWindow()->GetRenderWindow()->draw(*credits);
    game.GetWindow()->GetRenderWindow()->draw(*beenden);
};
