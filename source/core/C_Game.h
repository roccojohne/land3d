#pragma once

#include "../main.h"
#include "../io/C_Setting.h"

class C_Setting;
class C_Window;
class C_Game
{
    private:
       C_Setting *setting = nullptr;                                     // settings
       C_Window *mainwindow = nullptr;                                   // mainwindow
       

    public:
       C_Game();
       ~C_Game();
       bool run();
       C_Setting* GetSetting() {return setting; };
};