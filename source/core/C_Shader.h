#pragma once

#include "../main.h"

class C_Shader
{
    private:
        unsigned int vertexshaderID = 0;
        unsigned int fragmentshaderID = 0;
        unsigned int programID = 0;

        std::string vertexshaderCode;
        std::string fragmentshaderCode;

    public:
        C_Shader(C_Game &game, const char* vertexPath = "data\\shaders\\default_vs.glsl", const char* fragmentPath = "data\\shaders\\default_fs.glsl");
        ~C_Shader();

        void Use();

        void setBool(const std::string& name, bool value) const;
        void setInt(const std::string& name, int value) const;
        void setFloat(const std::string& name, float value) const;
};