#include "C_Shader.h"
#include <filesystem>
#include <sstream>
#include <fstream>


C_Shader::C_Shader(C_Game &game, const char* vertexPath, const char* fragmentPath)
{

    spdlog::info("creating shader ...");

    // 1. retrieve the vertex/fragment source code from filePath
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // open files
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // close file handlers
        vShaderFile.close();
        fShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure e)
    {
        spdlog::error("ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ ");
    }
    const char* vertexshaderCode = vertexCode.c_str();
    const char* fragmentshaderCode = fragmentCode.c_str();

    //****************************************************************************
    vertexshaderID = glCreateShader(GL_VERTEX_SHADER);
    fragmentshaderID = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertexshaderID, 1, &vertexshaderCode, 0);
    glShaderSource(fragmentshaderID, 1, &fragmentshaderCode, 0);

    glCompileShader(vertexshaderID);
    GLint vertex_compiled;
    glGetShaderiv(vertexshaderID, GL_COMPILE_STATUS, &vertex_compiled);
    if (vertex_compiled != GL_TRUE)
    {
        GLsizei log_length = 0;
        GLchar message[1024];
        glGetShaderInfoLog(vertexshaderID, 1024, &log_length, message);
        // Write the error to a log
        spdlog::critical(message);
    }

    glCompileShader(fragmentshaderID);
    GLint frag_compiled;
    glGetShaderiv(fragmentshaderID, GL_COMPILE_STATUS, &frag_compiled);
    if (vertex_compiled != GL_TRUE)
    {
        GLsizei log_length = 0;
        GLchar message[1024];
        glGetShaderInfoLog(fragmentshaderID, 1024, &log_length, message);
        // Write the error to a log
        spdlog::critical(message);
    }

    //***********************************************************************************

    programID = glCreateProgram();
    glAttachShader(programID, vertexshaderID);
    glAttachShader(programID, fragmentshaderID);
    glLinkProgram(programID);
    // print linking errors if any
    GLint success;
    glGetProgramiv(programID, GL_LINK_STATUS, &success);
    if (!success)
    {
        GLchar infoLog[1024];
        glGetProgramInfoLog(programID, 1024, NULL, infoLog);
        spdlog::error(infoLog);
    }

    // delete the shaders as they're linked into our program now and no longer necessary
    glDeleteShader(vertexshaderID);
    glDeleteShader(fragmentshaderID);

    spdlog::info("...done");
};

C_Shader::~C_Shader()
{
};

void C_Shader::Use()
{
    glUseProgram(programID);
};

void C_Shader::setBool(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(programID, name.c_str()), (int)value);
}
// ------------------------------------------------------------------------
void C_Shader::setInt(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(programID, name.c_str()), value);
}
// ------------------------------------------------------------------------
void C_Shader::setFloat(const std::string& name, float value) const
{
    glUniform1f(glGetUniformLocation(programID, name.c_str()), value);
}
