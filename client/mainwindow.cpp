#include "mainwindow.h"


Client * client;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Client::getInstance();
    ui_auth = new AuthWindow;
    ui_auth->show();
    connect(ui_auth, &AuthWindow::send_data, this, &MainWindow::slot_show);
    ui->MainTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->MainTable->setColumnCount(4);


}

MainWindow::~MainWindow()
{
    delete ui_auth;
    delete ui;

}

void MainWindow::slot_show(QString log)
{
    QString user_login = log;
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
                                   //ШТУКИ СПРАВА
void MainWindow::on_ButtonByCar_clicked()
{
    QString search = ui->SearchLineCar->text();
    qDebug() << search;
    ui->textEdit->setText(searchSetByCar(search));


    update_statistic(AuthWindow::getNameOfUser());
}

void MainWindow::on_ButtonByTrack_clicked()
{
    QString search = ui->SearchLineTrack->text();
    qDebug() << search;
    ui->textEdit->setText(searchSetByTrack(search));


    update_statistic(AuthWindow::getNameOfUser());
}

                                     //ВЫПАДАЮЩЕЕ МЕНЮ
void MainWindow::on_actionBy_car_triggered()
{
    QString search = QInputDialog::getText(0, "Search", "Car:",QLineEdit::Normal);
    qDebug() << search;
    ui->textEdit->setText(searchSetByCar(search));


    update_statistic(AuthWindow::getNameOfUser());
}

void MainWindow::on_actionBy_Track_triggered()
{
    QString search = QInputDialog::getText(0, "Search", "Track:", QLineEdit::Normal);
    qDebug() << search;
    ui->textEdit->setText(searchSetByTrack(search));


    update_statistic(AuthWindow::getNameOfUser());
}





//СТАТИСТИКА

void MainWindow::on_ButtonStat_clicked()
{
    QMessageBox temp;
    temp.setText("Поисков: " + check_statistic(AuthWindow::getNameOfUser()));
    temp.exec();
}


//ЗАГРУЗКА

void MainWindow::on_uploadButton_clicked()
{
    upload UploadWindow;
    UploadWindow.setModal(true);
    UploadWindow.exec();

}

//ТЕСТ БД

QString MainWindow::on_pushButton_clicked()
{
    QString res ="getAllSetups&";
    return Client::send_request_to_server(res);
}



