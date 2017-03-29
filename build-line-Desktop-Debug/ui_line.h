/********************************************************************************
** Form generated from reading UI file 'line.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINE_H
#define UI_LINE_H

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

class Ui_line
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *te2;
    QLabel *l5;
    QLabel *l1;
    QTextEdit *te1;
    QPushButton *p1;
    QLabel *label_6;
    QLabel *label_5;
    QTextEdit *te4;
    QLabel *label_3;
    QTextEdit *te3;
    QLabel *label_4;
    QPushButton *p2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *line)
    {
        if (line->objectName().isEmpty())
            line->setObjectName(QStringLiteral("line"));
        line->resize(786, 548);
        centralWidget = new QWidget(line);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 0, 91, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(194, 0, 101, 21));
        te2 = new QTextEdit(centralWidget);
        te2->setObjectName(QStringLiteral("te2"));
        te2->setGeometry(QRect(190, 50, 104, 21));
        l5 = new QLabel(centralWidget);
        l5->setObjectName(QStringLiteral("l5"));
        l5->setGeometry(QRect(430, 200, 361, 351));
        l1 = new QLabel(centralWidget);
        l1->setObjectName(QStringLiteral("l1"));
        l1->setGeometry(QRect(30, 190, 361, 351));
        te1 = new QTextEdit(centralWidget);
        te1->setObjectName(QStringLiteral("te1"));
        te1->setGeometry(QRect(20, 50, 104, 21));
        p1 = new QPushButton(centralWidget);
        p1->setObjectName(QStringLiteral("p1"));
        p1->setGeometry(QRect(40, 150, 97, 31));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(560, 560, 111, 31));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(130, 560, 65, 21));
        te4 = new QTextEdit(centralWidget);
        te4->setObjectName(QStringLiteral("te4"));
        te4->setGeometry(QRect(190, 100, 104, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(350, 50, 65, 21));
        te3 = new QTextEdit(centralWidget);
        te3->setObjectName(QStringLiteral("te3"));
        te3->setGeometry(QRect(20, 100, 104, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(350, 100, 101, 21));
        p2 = new QPushButton(centralWidget);
        p2->setObjectName(QStringLiteral("p2"));
        p2->setGeometry(QRect(180, 150, 97, 31));
        line->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(line);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 786, 26));
        line->setMenuBar(menuBar);
        mainToolBar = new QToolBar(line);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        line->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(line);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        line->setStatusBar(statusBar);

        retranslateUi(line);

        QMetaObject::connectSlotsByName(line);
    } // setupUi

    void retranslateUi(QMainWindow *line)
    {
        line->setWindowTitle(QApplication::translate("line", "line", 0));
        label->setText(QApplication::translate("line", "X coordinate", 0));
        label_2->setText(QApplication::translate("line", "Y coordinate", 0));
        l5->setText(QString());
        l1->setText(QString());
        p1->setText(QApplication::translate("line", "Show", 0));
        label_6->setText(QApplication::translate("line", "Bresenhems", 0));
        label_5->setText(QApplication::translate("line", "DDA", 0));
        label_3->setText(QApplication::translate("line", "DDA", 0));
        label_4->setText(QApplication::translate("line", "Bresenhems", 0));
        p2->setText(QApplication::translate("line", "Clear", 0));
    } // retranslateUi

};

namespace Ui {
    class line: public Ui_line {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINE_H
