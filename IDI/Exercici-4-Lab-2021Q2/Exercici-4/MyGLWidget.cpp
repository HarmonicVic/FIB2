
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

void MyGLWidget::initializeGL(){
    eixX = glm::vec3(1, 0, 0);
    eixY = glm::vec3(0, 1, 0);


    // Cal inicialitzar l'ús de les funcions d'OpenGL
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);

    glClearColor(0.5, 0.7, 1.0, 1.0); // defineix color de fons (d'esborrat)
    carregaShaders();

    pos1llumLoc = glGetUniformLocation (program->programId(), "llum1pos");
    pos2llumLoc = glGetUniformLocation (program->programId(), "llum2pos");
    pos3llumLoc = glGetUniformLocation (program->programId(), "llum3pos");

    col1llumLoc = glGetUniformLocation (program->programId(), "llum1col");
    col2llumLoc = glGetUniformLocation (program->programId(), "llum2col");
    col3llumLoc = glGetUniformLocation (program->programId(), "llum3col");

    primariLoc = glGetUniformLocation(program->programId(), "primari");

    iniEscena();
    iniCamera();
}

MyGLWidget::~MyGLWidget() {}

void MyGLWidget::setupLights(){
    LL4GLWidget::setupLights();


    glm::vec3 llum1pos(-3.5, 10.0, -3.5);
    llum1pos = glm::vec3((View * glm::vec4(llum1pos, 1.0f)));
    glm::vec3 llum2pos(3.5, 10.0, -3.5);
    llum2pos = glm::vec3((View * glm::vec4(llum2pos, 1.0f)));
    glm::vec3 llum3pos(3.5, 10.0, 3.5);
    llum3pos = glm::vec3((View * glm::vec4(llum3pos, 1.0f)));

    glm::vec3 llum1col(0.9, 0.2, 0.2);
    glm::vec3 llum2col(0.0, 1.0, 0.0);
    glm::vec3 llum3col(0.2, 0.2, 0.9);

    glUniform3fv(pos1llumLoc, 1, &llum1pos[0]);
    glUniform3fv(pos2llumLoc, 1, &llum2pos[0]);
    glUniform3fv(pos3llumLoc, 1, &llum3pos[0]);

    glUniform3fv(col1llumLoc, 1, &llum1col[0]);
    glUniform3fv(col2llumLoc, 1, &llum2col[0]);
    glUniform3fv(col3llumLoc, 1, &llum3col[0]);

    glUniform1i(primariLoc, primari);
}

void MyGLWidget::rightButton(){
    makeCurrent();
    angleCotxe += M_PI/4;
    update();
}

void MyGLWidget::leftButton(){
    makeCurrent();
    angleCotxe += -M_PI/4;
    update();
}

void MyGLWidget::keyPressEvent(QKeyEvent *e) {
    makeCurrent();
    switch (e->key()) {
    case Qt::Key_Left: {
        angleCotxe += -M_PI/4;
    }
    break;
    case Qt::Key_Right: {
        angleCotxe += M_PI/4;
    }
    break;
    case Qt::Key_F: {
        if (primari == 1) primari = 0;
        else primari = 1;
        glUniform1i(primariLoc, primari);
    }
    break;
    case Qt::Key_R: {
        primari = 1;
        glUniform1i(primariLoc, primari);
        angleCotxe = M_PI/4;
    }
    break;
        // no modifiqueu el següent comportament:
    default:
        LL4GLWidget::keyPressEvent(e);
    }
    update();
}
