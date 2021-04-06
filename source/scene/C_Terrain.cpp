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
        for (int y = 0; y < hightmapsize.y; y++)
            for (int x = 0; x < hightmapsize.x; x++)
            {
                
            }
    }
    catch (std::ifstream::failure e)
    {
        spdlog::error("can't read highmapfile {0} ", (char *)std::filesystem::absolute(filename).c_str());
    }

    Vertex v[24];
/*    v.vertex_position = {.0f, .5f, .0f};
    v.vertex_color = {1.f, .0f, .0f, 1.f};
    Vertex v1;
    v1.vertex_position = {-.5f, -.5f, .0f};
    v1.vertex_color = { .0f, 1.f, .0f, 1.f };
    Vertex v2;
    v2.vertex_position = { .5f, -.5f, .0f };
    v2.vertex_color = { .0f, .0f, 1.f, 1.f };*/

        v[0].vertex_position = {0.5, 0.0, 0.0 };
        v[0].vertex_color = {1.0, 0.0, 0.0, 1.0 };
        v[1].vertex_position = {0.0, 0.0, 0.0 };
        v[1].vertex_color = {0.0, 1.0, 0.0, 1.0 };
        v[2].vertex_position = {0.0, -0.5, 0.0 };
        v[2].vertex_color = {0.0, 0.0, 1.0, 1.0};

        v[3].vertex_position = {0.5, 0.0, 0.0 };
        v[3].vertex_color = {1.0, 0.0, 0.0, 1.0};
        v[4].vertex_position = {0.0, -0.5, 0.0 };
        v[4].vertex_color = {0.0, 1.0, 0.0, 1.0};
        v[5].vertex_position = {0.5, -0.5, 0.0 };
        v[5].vertex_color = {0.0, 0.0, 1.0, 1.0};

        v[6].vertex_position = { 1.0, 0.0, 0.0 };
        v[6].vertex_color = { 1.0, 0.0, 0.0, 1.0 };
        v[7].vertex_position = { 0.5, 0.0, 0.0 };
        v[7].vertex_color = { 0.0, 1.0, 0.0, 1.0 };
        v[8].vertex_position = { 0.5, -0.5, 0.0 };
        v[8].vertex_color = { 0.0, 0.0, 1.0, 1.0 };

        v[9].vertex_position = { 1.0, 0.0, 0.0 };
        v[9].vertex_color = { 1.0, 0.0, 0.0, 1.0 };
        v[10].vertex_position = { 0.5, -0.5, 0.0 };
        v[10].vertex_color = { 0.0, 1.0, 0.0, 1.0 };
        v[11].vertex_position = { 1.0, -0.5, 0.0 };
        v[11].vertex_color = { 0.0, 0.0, 1.0, 1.0 };

        v[12].vertex_position = { 0.5, -0.5, 0.0 };
        v[12].vertex_color = { 1.0, 0.0, 0.0, 1.0 };
        v[13].vertex_position = { 0.0, -0.5, 0.0 };
        v[13].vertex_color = { 0.0, 1.0, 0.0, 1.0 };
        v[14].vertex_position = { 0.0, -1.0, 0.0 };
        v[14].vertex_color = { 0.0, 0.0, 1.0, 1.0 };

        v[15].vertex_position = { 0.5, -0.5, 0.0 };
        v[15].vertex_color = { 1.0, 0.0, 0.0, 1.0 };
        v[16].vertex_position = { 0.0, -1.0, 0.0 };
        v[16].vertex_color = { 0.0, 1.0, 0.0, 1.0 };
        v[17].vertex_position = { 0.5, -1.0, 0.0 };
        v[17].vertex_color = { 0.0, 0.0, 1.0, 1.0 };

        v[18].vertex_position = { 1.0, -0.5, 0.0 };
        v[18].vertex_color = { 1.0, 0.0, 0.0, 1.0 };
        v[19].vertex_position = { 0.5, -0.5, 0.0 };
        v[19].vertex_color = { 0.0, 1.0, 0.0, 1.0 };
        v[20].vertex_position = { 0.5, -1.0, 0.0 };
        v[20].vertex_color = { 0.0, 0.0, 1.0, 1.0 };

        v[21].vertex_position = { 1.0, -0.5, 0.0 };
        v[21].vertex_color = { 1.0, 0.0, 0.0, 1.0 };
        v[22].vertex_position = { 0.5, -1.0, 0.0 };
        v[22].vertex_color = { 0.0, 1.0, 0.0, 1.0 };
        v[23].vertex_position = { 1.0, -1.0, 0.0 };
        v[23].vertex_color = { 0.0, 0.0, 1.0, 1.0 };

    mesh.push_back(v[0]);
    mesh.push_back(v[1]);
    mesh.push_back(v[2]);
    mesh.push_back(v[3]);
    mesh.push_back(v[4]);
    mesh.push_back(v[5]);
    mesh.push_back(v[6]);
    mesh.push_back(v[7]);
    mesh.push_back(v[8]);
    mesh.push_back(v[9]);
    mesh.push_back(v[10]);
    mesh.push_back(v[11]);
    mesh.push_back(v[12]);
    mesh.push_back(v[13]);
    mesh.push_back(v[14]);
    mesh.push_back(v[15]);
    mesh.push_back(v[16]);
    mesh.push_back(v[17]);
    mesh.push_back(v[18]);
    mesh.push_back(v[19]);
    mesh.push_back(v[20]);
    mesh.push_back(v[21]);
    mesh.push_back(v[22]);
    mesh.push_back(v[23]);

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
    glDrawArrays(GL_TRIANGLES, 0, 24);

};
