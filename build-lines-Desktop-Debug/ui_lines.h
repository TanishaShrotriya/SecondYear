/********************************************************************************
** Form generated from reading UI file 'lines.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINES_H
#define UI_LINES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lines
{
public:
    QWidget *centralWidget;
    QPushButton *p1;
    QLabel *l1;
    QLabel *l5;
    QPushButton *p2;
    QTextEdit *te1;
    QTextEdit *te2;
    QTextEdit *te3;
    QTextEdit *te4;
    QPushButton *p3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *lines)
    {
        if (lines->objectName().isEmpty())
            lines->setObjectName(QStringLiteral("lines"));
        lines->resize(839, 717);
        centralWidget = new QWidget(lines);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        p1 = new QPushButton(centralWidget);
        p1->setObjectName(QStringLiteral("p1"));
        p1->setGeometry(QRect(290, 10, 97, 31));
        l1 = new QLabel(centralWidget);
        l1->setObjectName(QStringLiteral("l1"));
        l1->setGeometry(QRect(20, 230, 801, 421));
        l5 = new QLabel(centralWidget);
        l5->setObjectName(QStringLiteral("l5"));
        l5->setGeometry(QRect(520, 280, 301, 281));
        p2 = new QPushButton(centralWidget);
        p2->setObjectName(QStringLiteral("p2"));
        p2->setGeometry(QRect(590, 10, 97, 31));
        te1 = new QTextEdit(centralWidget);
        te1->setObjectName(QStringLiteral("te1"));
        te1->setGeometry(QRect(120, 90, 104, 75));
        te2 = new QTextEdit(centralWidget);
        te2->setObjectName(QStringLiteral("te2"));
        te2->setGeometry(QRect(270, 90, 104, 75));
        te3 = new QTextEdit(centralWidget);
        te3->setObjectName(QStringLiteral("te3"));
        te3->setGeometry(QRect(430, 90, 104, 75));
        te4 = new QTextEdit(centralWidget);
        te4->setObjectName(QStringLiteral("te4"));
        te4->setGeometry(QRect(570, 90, 104, 75));
        p3 = new QPushButton(centralWidget);
        p3->setObjectName(QStringLiteral("p3"));
        p3->setGeometry(QRect(460, 40, 97, 31));
        lines->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(lines);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 839, 27));
        lines->setMenuBar(menuBar);
        mainToolBar = new QToolBar(lines);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        lines->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(lines);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        lines->setStatusBar(statusBar);

        retranslateUi(lines);

        QMetaObject::connectSlotsByName(lines);
    } // setupUi

    void retranslateUi(QMainWindow *lines)
    {
        lines->setWindowTitle(QApplication::translate("lines", "lines", 0));
        p1->setText(QApplication::translate("lines", "pattern", 0));
        l1->setText(QString());
        l5->setText(QString());
        p2->setText(QApplication::translate("lines", "Clear", 0));
        p3->setText(QApplication::translate("lines", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class lines: public Ui_lines {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINES_H
