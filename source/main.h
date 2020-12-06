#pragma once

//#define GLEW_STATIC 1

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <functional>

#include <gl/glew.h>
#include <SFML/Window.hpp>
#include <glm/glm.hpp>
#include <spdlog/spdlog.h>

#include "io/C_Setting.h"

#include "core/C_Game.h"
#include "core/C_Window.h"
#include "core/C_Shader.h"
#include "core/C_States.h"

class C_Setting;                                           // forward decl.
class C_Game;
class C_Window;
class C_State;
class C_State_Play;
class C_State_Menu;
class C_State_Setting;
class C_Shader;