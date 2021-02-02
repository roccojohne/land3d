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

    for (auto item : menulist)
        game.GetWindow()->GetRenderWindow()->draw(*item);
};


/*
*
*
*   playstate
*
*/

GLuint vbo = 0;
GLuint vao = 0;
GLfloat cdata[] =
{
    .9f, .1f, .9f, 1.f,
    .1f, .9f, .9f, 1.f,
    .9f, .9f, .1f, 1.f,
};

GLfloat vdata[] =
{
    0, 0, 0,
    0, 0, .1,
    .1, 0, 0,

    .1, 0, 0,
    .0, 0, .1,
    .1, 0, .1,

    .1, 0, 0,
    .1, 0, .1,
    .2, 0, 0,

    .2, 0, 0,
    .1, 0, .1,
    .2, 0, .1,

    .2, 0, 0,
    .2, 0, .1,
    .3, 0, 0,

    .3, 0, 0,
    .2, 0, .1,
    .3, 0, .1,

    .3, 0, 0,
    .3, 0, .1,
    .4, 0, 0,

    .4, 0, 0,
    .3, 0, .1,
    .4, 0, .1,

    .4, 0, 0,
    .4, 0, .1,
    .5, 0, 0,

    .5, 0, 0,
    .4, 0, .1,
    .5, 0, .1,


};
GLuint lll = 0;

C_States_Play::C_States_Play(C_Game& game)
{
    spdlog::info("render state init doen\n");

   // glMatrixMode(GL_MODELVIEW);
   // glLoadIdentity();
    //gluLookAt(posX, posY, posZ, targetX, targetY, targetZ, 0, 1, 0); // eye(x,y,z), focal(x,y,z), up(x,y,z)

    GLfloat lightKa[] = { .2f, .2f, .2f, 1.0f };  // ambient light
    GLfloat lightKd[] = { .7f, .7f, .7f, 1.0f };  // diffuse light
    GLfloat lightKs[] = { 1, 1, 1, 1 };           // specular light
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightKa);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightKd);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightKs);

    // position the light
    float lightPos[4] = { 0, 0, 20, 1 }; // positional light
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    glEnable(GL_LIGHT0);
 };

C_States_Play::~C_States_Play()
{

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
    glClearColor(.3, .3, .3, 1.);
    glClear(GL_COLOR_BUFFER_BIT);

    glTranslatef(-.5, -.5, 0); // move to upper left corner
    
    //glScalef(.5, .5, .5);
    glRotatef(ax, 1, 1, 0);
    //ax += 0.1;

    glRotatef(ay, 1, 0, 1);
    //ay += 0.1;

    glPushMatrix();
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    //glScalef(.5, .5, .5);
    glBegin(GL_TRIANGLES);
    // front faces
    //glNormal3f(0, 0, 1);
    // face v0-v1-v2
    glColor3f(1, 1, 1);
    int numtries = 10;
    for (int i = 0; i < 3 * numtries; i++)
    {
        glVertex3f(vdata[i], vdata[i++], vdata[i++]);
        spdlog::info(i);
    }
    glEnd();

    glPopMatrix();


    //spdlog::info("Frame rendering done...\n");
};
