#include <QPixmap>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include "QMessageBox"



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
    QPixmap LogoPic(":/resources/img/logo.png"); //лого слева сверху
    ui->logo->setPixmap(LogoPic);
    ui->NameOfUser->setText(log);
    show();
}

//EXIT

void MainWindow::on_actionExit_triggered(bool checked)
{
    close();
}



//ABOUT

void MainWindow::on_actionAbout_product_triggered()
{
    about AboutPage;
    AboutPage.setModal(true);
    AboutPage.exec();
}



//ПОИСК

void MainWindow::on_ButtonByCar_clicked()
{
  //поиск и вывод
    QString search = ui->SearchLineCar->text();
    qDebug() << search;


    update_statistic(1);

}


void MainWindow::on_ButtonByTrack_clicked()
{
      //поиск и вывод
    QString search = ui->SearchLineTrack->text();
    qDebug() << search;


    update_statistic(1);
}

void MainWindow::on_actionBy_car_triggered()
{
    QString search = QInputDialog::getText(0, "Search", "Car:",QLineEdit::Normal);
    qDebug() << search;


    update_statistic(1);
}

void MainWindow::on_actionBy_Track_triggered()
{
    QString search = QInputDialog::getText(0, "Search", "Track:", QLineEdit::Normal);
    qDebug() << search;


    update_statistic(1);
}



//СТАТИСТИКА

void MainWindow::on_ButtonStat_clicked()
{
    QMessageBox temp;
    temp.setText(QString("Поисков: %1").arg(check_statistic()));
    temp.exec();
}







