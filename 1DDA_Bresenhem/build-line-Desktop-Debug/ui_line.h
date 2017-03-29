/********************************************************************************
** Form generated from reading UI file 'line.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINE_H
#define UI_LINE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_line
{
public:
    QWidget *centralWidget;
    QLabel *l1;
    QLabel *label;
    QTextEdit *te4;
    QLabel *label_2;
    QTextEdit *te3;
    QLabel *label_4;
    QLabel *label_3;
    QPushButton *p2;
    QTextEdit *te1;
    QTextEdit *te2;
    QPushButton *p1;
    QLabel *l5;
    QLabel *label_5;
    QLabel *label_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *line)
    {
        if (line->objectName().isEmpty())
            line->setObjectName(QString::fromUtf8("line"));
        line->resize(916, 664);
        centralWidget = new QWidget(line);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        l1 = new QLabel(centralWidget);
        l1->setObjectName(QString::fromUtf8("l1"));
        l1->setGeometry(QRect(10, 190, 361, 351));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 91, 21));
        te4 = new QTextEdit(centralWidget);
        te4->setObjectName(QString::fromUtf8("te4"));
        te4->setGeometry(QRect(170, 100, 104, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(174, 0, 101, 21));
        te3 = new QTextEdit(centralWidget);
        te3->setObjectName(QString::fromUtf8("te3"));
        te3->setGeometry(QRect(0, 100, 104, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(330, 100, 101, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(330, 50, 65, 21));
        p2 = new QPushButton(centralWidget);
        p2->setObjectName(QString::fromUtf8("p2"));
        p2->setGeometry(QRect(160, 150, 97, 31));
        te1 = new QTextEdit(centralWidget);
        te1->setObjectName(QString::fromUtf8("te1"));
        te1->setGeometry(QRect(0, 50, 104, 21));
        te2 = new QTextEdit(centralWidget);
        te2->setObjectName(QString::fromUtf8("te2"));
        te2->setGeometry(QRect(170, 50, 104, 21));
        p1 = new QPushButton(centralWidget);
        p1->setObjectName(QString::fromUtf8("p1"));
        p1->setGeometry(QRect(20, 150, 97, 31));
        l5 = new QLabel(centralWidget);
        l5->setObjectName(QString::fromUtf8("l5"));
        l5->setGeometry(QRect(410, 200, 361, 351));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(110, 560, 65, 21));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(540, 560, 111, 31));
        line->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(line);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 916, 27));
        line->setMenuBar(menuBar);
        mainToolBar = new QToolBar(line);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        line->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(line);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        line->setStatusBar(statusBar);

        retranslateUi(line);

        QMetaObject::connectSlotsByName(line);
    } // setupUi

    void retranslateUi(QMainWindow *line)
    {
        line->setWindowTitle(QApplication::translate("line", "line", 0, QApplication::UnicodeUTF8));
        l1->setText(QString());
        label->setText(QApplication::translate("line", "X coordinate", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("line", "Y coordinate", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("line", "Bresenhems", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("line", "DDA", 0, QApplication::UnicodeUTF8));
        p2->setText(QApplication::translate("line", "Clear", 0, QApplication::UnicodeUTF8));
        p1->setText(QApplication::translate("line", "Show", 0, QApplication::UnicodeUTF8));
        l5->setText(QString());
        label_5->setText(QApplication::translate("line", "DDA", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("line", "Bresenhems", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class line: public Ui_line {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINE_H
