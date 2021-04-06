#pragma once

#include "../main.h"
#include "../core/C_Shader.h"
#include "../core/C_Game.h"

class C_Game;
class C_Shader;

class C_Entity
{
    protected:
        struct Vertex
        {
            glm::vec3 vertex_position;
            glm::vec4 vertex_color;
//            glm::vec3 vextex_normal;
//            glm::vec2 vextex_uv0;
        };

        C_Shader *shader = nullptr;
        
        GLuint vbo_pos = 0;
        GLuint vbo_col =  0;
        GLuint vao = 0;

    public:

};

class C_Terrain : public C_Entity
{
    private:
        std::vector<Vertex> mesh;
        glm::vec2 hightmapsize = {0, 0};
    public:
        C_Terrain(C_Game& game);
        void render(C_Game &game);
};