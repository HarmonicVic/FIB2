// MyGLWidget.cpp
#include "MyGLWidget.h"
#include <iostream>
#include <stdio.h>

#define printOpenGLError() printOglError(__FILE__, __LINE__)
#define CHECK() printOglError(__FILE__, __LINE__,__FUNCTION__)
#define DEBUG() std::cout << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << std::endl;

int MyGLWidget::printOglError(const char file[], int line, const char func[]) 
{
    GLenum glErr;
    int    retCode = 0;

    glErr = glGetError();
    const char * error = 0;
    switch (glErr)
    {
        case 0x0500:
            error = "GL_INVALID_ENUM";
            break;
        case 0x501:
            error = "GL_INVALID_VALUE";
            break;
        case 0x502: 
            error = "GL_INVALID_OPERATION";
            break;
        case 0x503:
            error = "GL_STACK_OVERFLOW";
            break;
        case 0x504:
            error = "GL_STACK_UNDERFLOW";
            break;
        case 0x505:
            error = "GL_OUT_OF_MEMORY";
            break;
        default:
            error = "unknown error!";
    }
    if (glErr != GL_NO_ERROR)
    {
        printf("glError in file %s @ line %d: %s function: %s\n",
                             file, line, error, func);
        retCode = 1;
    }
    return retCode;
}

MyGLWidget::~MyGLWidget() {
}

void MyGLWidget::iniEscena()
{
    ExamGLWidget::iniEscena();
    escala *= 2;
    anglePatricio = 0;
}

void MyGLWidget::paintGL ()   // Mètode que has de modificar
{
    //ExamGLWidget::paintGL();
    // Esborrem el frame-buffer i el depth-buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Pintem el terra
    glBindVertexArray (VAO_Terra);
    modelTransformTerra ();
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    if (scene == 0){
    // Pintem el Patricio
    glBindVertexArray (VAO_Patr);
    modelTransformPatricio (anglePatricio);
    glDrawArrays(GL_TRIANGLES, 0, patr.faces().size()*3);
    }
    else {
    // Pintem el cub 1
    glBindVertexArray(VAO_Cub);
    modelTransformCub (4.0, 0.0);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    // Pintem el cub 2
    modelTransformCub (5.0, 2*M_PI/3);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    // Pintem el cub 3
    modelTransformCub (6.0, -2*M_PI/3);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    }
    glBindVertexArray(0);
}

void MyGLWidget::modelTransformCub (float escala, float angle) 
{
    TG = glm::mat4(1.f);
    TG = glm::rotate(TG, angle, glm::vec3(0, 1, 0));
    TG = glm::translate(TG, glm::vec3(5, 0, 0));
    TG = glm::scale(TG, glm::vec3(escala));
    glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::modelTransformPatricio (float angle)    // Mètode que has de modificar
{
    TG = glm::mat4(1.f);
    TG = glm::rotate(TG, angle, glm::vec3(0,1,0));
    TG = glm::translate(TG, glm::vec3(5,0,0));
    TG = glm::rotate(TG, float(-M_PI/2), glm::vec3(0,1,0));
    TG = glm::rotate(TG, float(-M_PI/2), glm::vec3(1,0,0));
    TG = glm::scale(TG, glm::vec3 (escala, escala, escala));
    TG = glm::translate(TG, -centreBasePat);
    glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::viewTransform ()    // Mètode que has de modificar
{
  if (!camPlanta)
    ExamGLWidget::viewTransform();
  else
  {
    // Codi per a la viewMatrix de la Càmera-2
  }
}

void MyGLWidget::projectTransform ()
{
  if (!camPlanta)
    ExamGLWidget::projectTransform();
  else
  {
    // Codi per a la projectMatrix de la Càmera-2
  }
}

void MyGLWidget::keyPressEvent(QKeyEvent* event) {
  makeCurrent();
  switch (event->key()) {
  case Qt::Key_V: {
        if (scene == 0) scene = 1;
        else scene = 0;
        update();
    break;
	}
  case Qt::Key_1: {
      anglePatricio = 0;
      update();
    break;
	}
  case Qt::Key_2: {
      anglePatricio = 2*M_PI/3;
      update();
    break;
	}
  case Qt::Key_3: {
      anglePatricio = -2*M_PI/3;
      update();
    break;
	}
  case Qt::Key_F: {
      // ...
    break;
	}
  case Qt::Key_C: {
      // ...
    break;
	}
  case Qt::Key_Right: {
      // ...
    break;
	}
  case Qt::Key_Left: {
      // ...
    break;
	}
  case Qt::Key_R: {
      // ...
    break;
	}
  default: ExamGLWidget::keyPressEvent(event); break;
  }
  update();
}

