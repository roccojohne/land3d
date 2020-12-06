#pragma once


#include "../main.h"

class C_Setting
{
    private:
       struct data // with some defaults
       {
           int window_width = 800;                              // window or screen resolution
           int window_height = 600;
           bool fullscreen = false;                             // fullscreen or windowmode
           std::string guifontname = "data\\fonts\\gui.font";   // font for gui
           bool loogging = true;                                // logging
           std::string assetpath = "data\\assets\\";            // asset path
       };
       std::string settingfile = "data\\setting.dat";

    public:

       data settingdata;

       enum ID_SETTING
       {
           ID_WINDOW_WIDTH = 1000,
           ID_WINDOW_HEIGHT,
           ID_FULLSCREEN,
           ID_USELOGGING,
       };
       
       C_Setting();                                          // ctor
       ~C_Setting();                                         // detor (auto save settings on exit)
       bool Load();                                          // read setting from file
       bool Save();                                          // write setting to file
       void Set(const unsigned int& id, ...);                // set data to settindata
       auto Get(const unsigned int& id);                     // get data settingdata 
};