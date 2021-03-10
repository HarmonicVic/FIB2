#include <QApplication>
#include <QPushButton>

int main(int argc, char** argv){
    QApplication a(argc, argv);
    
    QPushButton hello("Hello Qt!", NULL);

    hello.resize(150, 30);

    hello.show();

    return a.exec();
}