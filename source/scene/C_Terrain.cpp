#include "C_Entity.h"

C_Terrain::C_Terrain(C_Game& game)
{
    shader = new C_Shader(game);
    //mesh = new std::vector<Vertex>;

    char filename[] = "data\\assets\\terrain.pgm";
    
    std::ifstream hfile;
    hfile.open(filename);
    char data[64];
    hfile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        spdlog::info("Highmapfile successfull open...");
        /*while (hfile.is_open())
        {
            hfile.getline(data, 64);
            std::cout << data;
        }
        std::cout << "\n";*/

        std::stringstream filedata;
        // read file's buffer contents into streams
        filedata << hfile.rdbuf();
       
        hfile.close();
        //std::cout << "data:\n" << filedata.str();
        //while (!filedata.good())
        filedata.getline(data, 64);                         // get file header, must be 'P2'
        if (data[0] == 'P' && data[1] == '2')
            spdlog::info("Portable Graymap found\n");
        filedata.getline(data, 64);                         // get comment
        if (data[0] == '#')
            spdlog::info("{0}", data);
        //filedata.getline(data, 64);                         // width and height
        filedata >> hightmapsize.x >> hightmapsize.y;
        spdlog::info("X {0} Y {1}", hightmapsize.x, hightmapsize.y);
        // mesh generating
        unsigned int value = 0;
        for (int y = 0; y < hightmapsize.y; y++)
            for (int x = 0; x < hightmapsize.x; x++)
            {
                filedata >> value;
                Vertex *v = new Vertex;
                v->vertex_color.r = float(value) / 255.f;
                v->vertex_color.r = float(value) / 255.f;
                v->vertex_color.r = float(value) / 255.f;
                v->vertex_color.a = 1.0f;
                v->vertex_position.x = x * .1f;
                v->vertex_position.y = y * .1f;
                v->vertex_position.z = -1.f + float(value) / 255.f;

               // spdlog::info("Vertexposition : {0} {1} {2}", v->vertex_position.x, v->vertex_position.y, v->vertex_position.z);
                mesh.push_back(v);
            }
    }
    catch (std::ifstream::failure e)
    {
        spdlog::error("can't read highmapfile {0} ", (char *)std::filesystem::absolute(filename).c_str());
    }
    

    spdlog::info("Triangles : {0} Memorysize : {1} bytes", (mesh.size() / 3), (mesh.size() * (sizeof(Vertex))));

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo_pos);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_pos);
    glBufferData(GL_ARRAY_BUFFER, mesh.size() * sizeof(Vertex), &mesh[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(glm::vec3) + sizeof(glm::vec4), (GLvoid *)0);
    
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 4, GL_FLOAT, false, sizeof(glm::vec3) + sizeof(glm::vec4), (GLvoid *)offsetof(Vertex, vertex_color.r));

};

void C_Terrain::render(C_Game& game)
{
    shader->Use();
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, mesh.size());

};
