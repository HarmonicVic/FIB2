#version 330 core

in vec3  fvertex;
in vec3  fnormal;
in vec3  fmatamb;
in vec3  fmatdiff;
in vec3  fmatspec;
in float fmatshin;

uniform vec3 posFocus;
uniform vec3 colFocus;

uniform vec3 llum1pos;
uniform vec3 llum2pos;
uniform vec3 llum3pos;

uniform vec3 llum1col;
uniform vec3 llum2col;
uniform vec3 llum3col;

//luz primaria (== 1) o focos secundarios (== 0)
uniform int primari;

uniform mat4 TG;
uniform mat4 Proj;
uniform mat4 View;

out vec4 FragColor;

vec3 llumAmbient = vec3(0.1, 0.1, 0.1);

vec3 Ambient() {
  return llumAmbient*fmatamb;
}


vec3 Lambert (vec3 NormSCO, vec3 L, vec3 color)
{
  // Fixeu-vos que SOLS es retorna el terme de Lambert!
  // S'assumeix que els vectors que es reben com a paràmetres estan normalitzats
  vec3 colRes = vec3(0);
  if (dot (L, NormSCO) > 0)
    colRes = color * fmatdiff * dot (L, NormSCO);
  return (colRes);
}

vec3 Phong (vec3 NormSCO, vec3 L, vec3 vertSCO, vec3 color)
{
  // Fixeu-vos que SOLS es retorna el terme especular!
  // Assumim que els vectors estan normalitzats
  vec3 colRes = vec3 (0);
  // Si la llum ve de darrera o el material és mate no fem res
  if ((dot(NormSCO,L) < 0) || (fmatshin == 0))
    return colRes;  // no hi ha component especular

  vec3 R = reflect(-L, NormSCO); // equival a: 2.0*dot(NormSCO,L)*NormSCO - L;
  vec3 V = normalize(-vertSCO); // perquè la càmera està a (0,0,0) en SCO

  if (dot(R, V) < 0)
    return colRes;  // no hi ha component especular

  float shine = pow(max(0.0, dot(R, V)), fmatshin);
  return (colRes + fmatspec * color * shine);
}


void main()
{
    if (primari == 1){
        vec3 L     = normalize(posFocus - fvertex);
        vec3 color = Ambient() +
                    Lambert(normalize(fnormal), L, colFocus) +
                    Phong (normalize(fnormal), L, fvertex, colFocus);

        FragColor = vec4(color, 1);
    }
    else {
        vec3 L1     = normalize(llum1pos - fvertex);
        vec3 L2     = normalize(llum2pos - fvertex);
        vec3 L3     = normalize(llum3pos - fvertex);
        vec3 color;
            color = Ambient()
                    + Lambert(normalize(fnormal), L1, llum1col)
                    + Phong (normalize(fnormal), L1, fvertex, llum1col);
            color +=
                    Lambert(normalize(fnormal), L2, llum2col)
                    + Phong (normalize(fnormal), L2, fvertex, llum2col);
            color +=
                    Lambert(normalize(fnormal), L3, llum3col)
                    + Phong (normalize(fnormal), L3, fvertex, llum3col);
        FragColor = vec4(color, 1);
    }
 }

