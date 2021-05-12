/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(610, 427);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 70, 60, 44));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(163, 15, 281, 101));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_4 = new QLabel(widget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_3 = new QLabel(widget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_5 = new QLabel(widget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(widget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_3->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_7 = new QLabel(widget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_4->addWidget(label_7);

        label_8 = new QLabel(widget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_4->addWidget(label_8);


        horizontalLayout->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
