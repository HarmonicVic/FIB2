// MyGLWidget.h
#include "LL4GLWidget.h"

class MyGLWidget : public LL4GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : LL4GLWidget(parent) {}
    ~MyGLWidget();
protected:
    GLint pos1llumLoc, pos2llumLoc, pos3llumLoc, col1llumLoc, col2llumLoc, col3llumLoc;
    GLint primari = 1;
    GLint primariLoc;
    virtual void initializeGL();

    virtual void setupLights();

public slots:
    void rightButton();
    void leftButton();

  private:
    int printOglError(const char file[], int line, const char func[]);
    virtual void keyPressEvent (QKeyEvent *);
};
