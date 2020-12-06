#pragma once

#include "../main.h"

class C_Shader
{
    private:
    unsigned int vertexshaderID = 0;
    unsigned int fragmentshaderID = 0;
    unsigned int programID = 0;

    std::string vertexshaderCode = "";
    std::string fragmentshaderCode = "";

    public:
    enum shaderid {ID_FRAGMENTSHADER = 1000, ID_VERTEXSHADER};

    C_Shader(C_Game &game);
    ~C_Shader();
    bool LoadShader(std::string &codefile, const int &type);
    bool CreateShader();
    bool LinkShader();
    void Bind();
};