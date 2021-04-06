#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 ccolor;

//uniform mat4 MVP;

out vec4 fcolor;

void main()
{
   gl_Position = /*MVP * */vec4(aPos.x, aPos.y, aPos.z, 1.0);
   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
   fcolor = ccolor;
   //fcolor = vec4(ccolor, 1.0);
}
