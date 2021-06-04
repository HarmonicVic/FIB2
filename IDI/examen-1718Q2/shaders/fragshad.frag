#version 330 core

//in vec3 fcolor;
in vec3 color;

out vec4 FragColor;

void main()
{	
    FragColor = (color, 1);
}
