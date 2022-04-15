/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionAbout_product;
    QAction *actionBy_car;
    QAction *actionBy_Track;
    QWidget *centralwidget;
    QLabel *NameOfUser;
    QTableWidget *MainTable;
    QGroupBox *SearchBox;
    QLineEdit *SearchLineCar;
    QLineEdit *SearchLineTrack;
    QPushButton *ButtonByCar;
    QPushButton *ButtonByTrack;
    QLabel *logo;
    QPushButton *ButtonStat;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuSearch;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAbout_product = new QAction(MainWindow);
        actionAbout_product->setObjectName(QString::fromUtf8("actionAbout_product"));
        actionBy_car = new QAction(MainWindow);
        actionBy_car->setObjectName(QString::fromUtf8("actionBy_car"));
        actionBy_Track = new QAction(MainWindow);
        actionBy_Track->setObjectName(QString::fromUtf8("actionBy_Track"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        NameOfUser = new QLabel(centralwidget);
        NameOfUser->setObjectName(QString::fromUtf8("NameOfUser"));
        NameOfUser->setGeometry(QRect(570, 20, 221, 51));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(true);
        NameOfUser->setFont(font);
        NameOfUser->setAlignment(Qt::AlignCenter);
        MainTable = new QTableWidget(centralwidget);
        if (MainTable->columnCount() < 4)
            MainTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        MainTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        MainTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        MainTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        MainTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        MainTable->setObjectName(QString::fromUtf8("MainTable"));
        MainTable->setGeometry(QRect(40, 170, 591, 551));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainTable->sizePolicy().hasHeightForWidth());
        MainTable->setSizePolicy(sizePolicy);
        MainTable->setLayoutDirection(Qt::LeftToRight);
        MainTable->setAutoFillBackground(false);
        MainTable->setShowGrid(true);
        MainTable->setRowCount(0);
        MainTable->horizontalHeader()->setCascadingSectionResizes(false);
        MainTable->horizontalHeader()->setStretchLastSection(true);
        MainTable->verticalHeader()->setCascadingSectionResizes(false);
        MainTable->verticalHeader()->setStretchLastSection(true);
        SearchBox = new QGroupBox(centralwidget);
        SearchBox->setObjectName(QString::fromUtf8("SearchBox"));
        SearchBox->setEnabled(true);
        SearchBox->setGeometry(QRect(640, 170, 151, 291));
        SearchLineCar = new QLineEdit(SearchBox);
        SearchLineCar->setObjectName(QString::fromUtf8("SearchLineCar"));
        SearchLineCar->setGeometry(QRect(30, 80, 101, 24));
        SearchLineTrack = new QLineEdit(SearchBox);
        SearchLineTrack->setObjectName(QString::fromUtf8("SearchLineTrack"));
        SearchLineTrack->setGeometry(QRect(30, 180, 101, 24));
        ButtonByCar = new QPushButton(SearchBox);
        ButtonByCar->setObjectName(QString::fromUtf8("ButtonByCar"));
        ButtonByCar->setGeometry(QRect(30, 110, 101, 24));
        ButtonByTrack = new QPushButton(SearchBox);
        ButtonByTrack->setObjectName(QString::fromUtf8("ButtonByTrack"));
        ButtonByTrack->setGeometry(QRect(30, 210, 101, 24));
        logo = new QLabel(centralwidget);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(10, 10, 101, 81));
        logo->setScaledContents(true);
        ButtonStat = new QPushButton(centralwidget);
        ButtonStat->setObjectName(QString::fromUtf8("ButtonStat"));
        ButtonStat->setGeometry(QRect(620, 80, 121, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuSearch = new QMenu(menuMenu);
        menuSearch->setObjectName(QString::fromUtf8("menuSearch"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuMenu->addAction(menuSearch->menuAction());
        menuMenu->addAction(actionExit);
        menuSearch->addSeparator();
        menuSearch->addAction(actionBy_car);
        menuSearch->addAction(actionBy_Track);
        menuAbout->addSeparator();
        menuAbout->addAction(actionAbout_product);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionAbout_product->setText(QCoreApplication::translate("MainWindow", "About product", nullptr));
        actionBy_car->setText(QCoreApplication::translate("MainWindow", "By Car", nullptr));
        actionBy_Track->setText(QCoreApplication::translate("MainWindow", "By Track", nullptr));
        NameOfUser->setText(QCoreApplication::translate("MainWindow", "UserName", nullptr));
        QTableWidgetItem *___qtablewidgetitem = MainTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Car", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = MainTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Track", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = MainTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Download", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = MainTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Name of the setup", nullptr));
        SearchBox->setTitle(QCoreApplication::translate("MainWindow", "Search something", nullptr));
        SearchLineCar->setPlaceholderText(QCoreApplication::translate("MainWindow", "Audi R8", nullptr));
        SearchLineTrack->setText(QString());
        SearchLineTrack->setPlaceholderText(QCoreApplication::translate("MainWindow", "Spa", nullptr));
        ButtonByCar->setText(QCoreApplication::translate("MainWindow", "Search by car", nullptr));
        ButtonByTrack->setText(QCoreApplication::translate("MainWindow", "Search by track", nullptr));
        logo->setText(QString());
        ButtonStat->setText(QCoreApplication::translate("MainWindow", "Statistic of searching", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        menuSearch->setTitle(QCoreApplication::translate("MainWindow", "Search", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
