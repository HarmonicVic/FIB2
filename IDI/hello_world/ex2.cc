#include <QApplication>
#include <QPushButton>
#include <QFrame>
#include <QLayout>
#include <QLineEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString fontFamily = "Arial";
    a.setFont(fontFamily);

    QFrame F(0, NULL);

    QHBoxLayout* cH = new QHBoxLayout(&F);

    QLineEdit* le = new QLineEdit(&F);
    cH->addWidget(le);

    QSpacerItem *sp = new QSpacerItem(100, 100);
    cH->addItem(sp);

    QPushButton* ok = new QPushButton("D'acord", &F);
    cH->addWidget(ok);

    QPushButton* surt = new QPushButton("Surt", &F);
    cH->addWidget(surt);

    F.show();
    return a.exec();
}
