#version 330 core

in vec3 fcolor;
//in int eleccion;

out vec4 FragColor;

void main() {
    //if(eleccion == 2) FragColor = vec4(0.2, 0.2, 0.2 , 1);
     FragColor = vec4(fcolor, 1);
}

