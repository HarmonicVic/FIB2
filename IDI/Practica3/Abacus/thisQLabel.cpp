#include "thisQLabel.h"
#include <QString>
// #include <QDebug>

thisQLabel::thisQLabel(QWidget*parent):QLabel(parent){

}

void thisQLabel::increment()
{
    QString str = text();
    if (str == "1"){
        setNum(0);
        setStyleSheet("background: green");
        emit overflow();
        // qDebug() << "hello";
    }
    else{
        setNum(1);
        setStyleSheet("background: yellow");
    }
}

void thisQLabel::reset()
{
    setNum(0);
    setStyleSheet("background: green");
}