/********************************************************************************
** Form generated from reading UI file 'linestyles.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINESTYLES_H
#define UI_LINESTYLES_H

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

class Ui_linestyles
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *linestyles)
    {
        if (linestyles->objectName().isEmpty())
            linestyles->setObjectName(QStringLiteral("linestyles"));
        linestyles->resize(1000, 2000);
        centralWidget = new QWidget(linestyles);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 65, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 60, 65, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(250, 10, 65, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(250, 70, 65, 21));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 140, 1000, 800));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 110, 65, 21));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(70, 0, 113, 33));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(80, 50, 113, 33));
        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(290, 0, 113, 33));
        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(290, 50, 113, 33));
        lineEdit_5 = new QLineEdit(centralWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(80, 110, 113, 33));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(450, 0, 97, 31));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(580, 0, 97, 31));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(710, 0, 97, 31));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(850, 0, 97, 31));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(450, 50, 101, 31));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(580, 50, 97, 31));
        linestyles->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(linestyles);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 26));
        linestyles->setMenuBar(menuBar);
        mainToolBar = new QToolBar(linestyles);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        linestyles->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(linestyles);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        linestyles->setStatusBar(statusBar);

        retranslateUi(linestyles);

        QMetaObject::connectSlotsByName(linestyles);
    } // setupUi

    void retranslateUi(QMainWindow *linestyles)
    {
        linestyles->setWindowTitle(QApplication::translate("linestyles", "linestyles", 0));
        label->setText(QApplication::translate("linestyles", "  x1", 0));
        label_2->setText(QApplication::translate("linestyles", "y1", 0));
        label_3->setText(QApplication::translate("linestyles", "x2", 0));
        label_4->setText(QApplication::translate("linestyles", "y2", 0));
        label_5->setText(QApplication::translate("linestyles", "                                                     Your Line will appear here!!", 0));
        label_6->setText(QApplication::translate("linestyles", "width", 0));
        pushButton->setText(QApplication::translate("linestyles", "Thin Line", 0));
        pushButton_2->setText(QApplication::translate("linestyles", "Thick Line", 0));
        pushButton_3->setText(QApplication::translate("linestyles", "Dotted Line", 0));
        pushButton_4->setText(QApplication::translate("linestyles", "Dashed Line", 0));
        pushButton_5->setText(QApplication::translate("linestyles", "Dot-Dashed", 0));
        pushButton_6->setText(QApplication::translate("linestyles", "Clear All!", 0));
    } // retranslateUi

};

namespace Ui {
    class linestyles: public Ui_linestyles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINESTYLES_H
