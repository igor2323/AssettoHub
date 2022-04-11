#include <QPixmap>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui_auth = new AuthWindow;
    ui_auth->show();
    connect(ui_auth, &AuthWindow::send_data, this, &MainWindow::slot_show);

}

MainWindow::~MainWindow()
{
    delete ui_auth;
    delete ui;
}

void MainWindow::slot_show(QString log)
{
    QPixmap LogoPic(":/resources/img/logo.png");
    ui->logo->setPixmap(LogoPic);
    ui->NameOfUser->setText(log);
    show();
}



void MainWindow::on_actionExit_triggered(bool checked)
{
    close();
}





void MainWindow::on_actionAbout_product_triggered()
{
    about AboutPage;
    AboutPage.setModal(true);
    AboutPage.exec();
}

