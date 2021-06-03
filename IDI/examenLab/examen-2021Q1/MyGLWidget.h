#include "ExamGLWidget.h"

class MyGLWidget:public ExamGLWidget
{
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : ExamGLWidget(parent) {}
    ~MyGLWidget();

  protected:
    virtual void paintGL ();
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void modelTransformCub (float escala, float angle);
    virtual void modelTransformPatricio (float angle);
    virtual void projectTransform ();
    virtual void viewTransform ();
    virtual void iniEscena ();

    int scene = 1;
    float anglePatricio;

  private:
    int printOglError(const char file[], int line, const char func[]);
};
