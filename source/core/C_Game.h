#pragma once

#include "../main.h"
#include "../io/C_Setting.h"

class C_Setting;
class C_Window;
class C_States;
class C_States_Menu;

class C_Game
{
    private:
       sf::Clock *rendertimer = nullptr;

       C_Setting *setting = nullptr;                                     // settings
       C_Window *mainwindow = nullptr;                                   // mainwindow
       
       C_States *currentstate = nullptr;                                 // currend renderstate
    public:
        enum ID_STATE
        {
            ID_STATES_MENU = 1000,
            ID_STATES_PLAY,
        };

       C_Game();
       ~C_Game();
       bool run();
       C_Setting* GetSetting() {return setting; };
       C_Window* GetWindow() {return mainwindow; };
       void changeCurrentState(const int state_id);
};