#pragma once

class C_Mesh
{
    private:
        std::string mesh_file_name = "mesh.msh";

        struct mesh_data
        {
            glm::vec3 position = {0.f, .0f, .0f};
            glm::vec3 normal = { 0.f, .0f, .0f };
            glm::vec2 texcoord0 = {.0f, .0f};
        };

    public:
};