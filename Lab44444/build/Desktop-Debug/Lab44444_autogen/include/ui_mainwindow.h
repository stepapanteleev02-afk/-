/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *resetButton;
    QPushButton *saveButton;
    QLineEdit *authorEdit;
    QLineEdit *titleEdit;
    QLineEdit *codeEdit;
    QLineEdit *ratioEdit;
    QRadioButton *radioPaper;
    QRadioButton *radioElectronic;
    QCheckBox *genreDetective;
    QCheckBox *genreFantasy;
    QCheckBox *genreRomance;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(507, 413);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName("resetButton");
        resetButton->setGeometry(QRect(110, 330, 80, 24));
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(200, 330, 80, 24));
        authorEdit = new QLineEdit(centralwidget);
        authorEdit->setObjectName("authorEdit");
        authorEdit->setGeometry(QRect(150, 10, 113, 24));
        titleEdit = new QLineEdit(centralwidget);
        titleEdit->setObjectName("titleEdit");
        titleEdit->setGeometry(QRect(150, 50, 113, 24));
        codeEdit = new QLineEdit(centralwidget);
        codeEdit->setObjectName("codeEdit");
        codeEdit->setGeometry(QRect(150, 90, 113, 24));
        ratioEdit = new QLineEdit(centralwidget);
        ratioEdit->setObjectName("ratioEdit");
        ratioEdit->setGeometry(QRect(140, 130, 113, 24));
        radioPaper = new QRadioButton(centralwidget);
        radioPaper->setObjectName("radioPaper");
        radioPaper->setGeometry(QRect(140, 180, 90, 21));
        radioElectronic = new QRadioButton(centralwidget);
        radioElectronic->setObjectName("radioElectronic");
        radioElectronic->setGeometry(QRect(250, 180, 121, 21));
        genreDetective = new QCheckBox(centralwidget);
        genreDetective->setObjectName("genreDetective");
        genreDetective->setGeometry(QRect(140, 210, 76, 21));
        genreFantasy = new QCheckBox(centralwidget);
        genreFantasy->setObjectName("genreFantasy");
        genreFantasy->setGeometry(QRect(140, 240, 76, 21));
        genreRomance = new QCheckBox(centralwidget);
        genreRomance->setObjectName("genreRomance");
        genreRomance->setGeometry(QRect(140, 280, 76, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 507, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        radioPaper->setText(QCoreApplication::translate("MainWindow", "\320\221\321\203\320\274\320\260\320\266\320\275\320\276\320\265", nullptr));
        radioElectronic->setText(QCoreApplication::translate("MainWindow", "\320\255\320\273\320\265\320\272\321\202\321\200\320\276\320\275\320\275\320\276\320\265", nullptr));
        genreDetective->setText(QCoreApplication::translate("MainWindow", "CheckBox", nullptr));
        genreFantasy->setText(QCoreApplication::translate("MainWindow", "CheckBox", nullptr));
        genreRomance->setText(QCoreApplication::translate("MainWindow", "CheckBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
