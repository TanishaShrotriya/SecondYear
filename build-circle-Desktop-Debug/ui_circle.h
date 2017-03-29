/********************************************************************************
** Form generated from reading UI file 'circle.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CIRCLE_H
#define UI_CIRCLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_circle
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *circle)
    {
        if (circle->objectName().isEmpty())
            circle->setObjectName(QStringLiteral("circle"));
        circle->resize(688, 493);
        centralWidget = new QWidget(circle);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(40, 40, 113, 33));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(190, 40, 113, 33));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 20, 65, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(240, 20, 65, 21));
        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(110, 120, 113, 33));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(160, 100, 65, 21));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 190, 97, 31));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 190, 97, 31));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(310, 20, 361, 341));
        circle->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(circle);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 688, 27));
        circle->setMenuBar(menuBar);
        mainToolBar = new QToolBar(circle);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        circle->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(circle);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        circle->setStatusBar(statusBar);

        retranslateUi(circle);

        QMetaObject::connectSlotsByName(circle);
    } // setupUi

    void retranslateUi(QMainWindow *circle)
    {
        circle->setWindowTitle(QApplication::translate("circle", "circle", 0));
        label->setText(QApplication::translate("circle", "x", 0));
        label_2->setText(QApplication::translate("circle", "y", 0));
        label_3->setText(QApplication::translate("circle", "r", 0));
        pushButton->setText(QApplication::translate("circle", "Draw", 0));
        pushButton_2->setText(QApplication::translate("circle", "Clear", 0));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class circle: public Ui_circle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIRCLE_H
