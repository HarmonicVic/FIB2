/********************************************************************************
** Form generated from reading UI file 'abacus.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABACUS_H
#define UI_ABACUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <thisqlabel.h>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *Decimes;
    QLabel *Unitats;
    QVBoxLayout *verticalLayout;
    QLabel *dec4;
    QLabel *uni4;
    QVBoxLayout *verticalLayout_4;
    QLabel *dec2;
    QLabel *uni2;
    QVBoxLayout *verticalLayout_2;
    QLabel *dec1;
    thisQLabel *uni1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Numero;
    QLCDNumber *LCD;
    QPushButton *IncrementB;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *ResetB;
    QPushButton *ExitB;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(604, 410);
        Form->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_5 = new QVBoxLayout(Form);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        Decimes = new QLabel(Form);
        Decimes->setObjectName(QString::fromUtf8("Decimes"));

        verticalLayout_3->addWidget(Decimes);

        Unitats = new QLabel(Form);
        Unitats->setObjectName(QString::fromUtf8("Unitats"));

        verticalLayout_3->addWidget(Unitats);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        dec4 = new QLabel(Form);
        dec4->setObjectName(QString::fromUtf8("dec4"));

        verticalLayout->addWidget(dec4);

        uni4 = new QLabel(Form);
        uni4->setObjectName(QString::fromUtf8("uni4"));

        verticalLayout->addWidget(uni4);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        dec2 = new QLabel(Form);
        dec2->setObjectName(QString::fromUtf8("dec2"));

        verticalLayout_4->addWidget(dec2);

        uni2 = new QLabel(Form);
        uni2->setObjectName(QString::fromUtf8("uni2"));

        verticalLayout_4->addWidget(uni2);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        dec1 = new QLabel(Form);
        dec1->setObjectName(QString::fromUtf8("dec1"));

        verticalLayout_2->addWidget(dec1);

        uni1 = new thisQLabel(Form);
        uni1->setObjectName(QString::fromUtf8("uni1"));
        uni1->setScaledContents(false);

        verticalLayout_2->addWidget(uni1);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Numero = new QLabel(Form);
        Numero->setObjectName(QString::fromUtf8("Numero"));

        horizontalLayout_2->addWidget(Numero);

        LCD = new QLCDNumber(Form);
        LCD->setObjectName(QString::fromUtf8("LCD"));
        LCD->setMode(QLCDNumber::Oct);

        horizontalLayout_2->addWidget(LCD);


        verticalLayout_5->addLayout(horizontalLayout_2);

        IncrementB = new QPushButton(Form);
        IncrementB->setObjectName(QString::fromUtf8("IncrementB"));
        IncrementB->setCheckable(false);

        verticalLayout_5->addWidget(IncrementB);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        ResetB = new QPushButton(Form);
        ResetB->setObjectName(QString::fromUtf8("ResetB"));

        horizontalLayout_3->addWidget(ResetB);

        ExitB = new QPushButton(Form);
        ExitB->setObjectName(QString::fromUtf8("ExitB"));

        horizontalLayout_3->addWidget(ExitB);


        verticalLayout_5->addLayout(horizontalLayout_3);


        retranslateUi(Form);
        QObject::connect(IncrementB, SIGNAL(clicked()), uni1, SLOT(increment()));
        QObject::connect(ResetB, SIGNAL(clicked()), uni1, SLOT(reset()));
        QObject::connect(ExitB, SIGNAL(clicked()), Form, SLOT(close()));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Abacus", nullptr));
        Decimes->setText(QCoreApplication::translate("Form", "Decimes:", nullptr));
        Unitats->setText(QCoreApplication::translate("Form", "Unitats:", nullptr));
        dec4->setText(QCoreApplication::translate("Form", "0", nullptr));
        uni4->setText(QCoreApplication::translate("Form", "0", nullptr));
        dec2->setText(QCoreApplication::translate("Form", "0", nullptr));
        uni2->setText(QCoreApplication::translate("Form", "0", nullptr));
        dec1->setText(QCoreApplication::translate("Form", "0", nullptr));
        uni1->setText(QCoreApplication::translate("Form", "0", nullptr));
        Numero->setText(QCoreApplication::translate("Form", "Numero:", nullptr));
        IncrementB->setText(QCoreApplication::translate("Form", "Increment!", nullptr));
        ResetB->setText(QCoreApplication::translate("Form", "Reset", nullptr));
        ExitB->setText(QCoreApplication::translate("Form", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABACUS_H
