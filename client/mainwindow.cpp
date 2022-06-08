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
    ui->MainTable->setColumnCount(7);
    ui->MainTable->setRowCount(0);

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

    QString resultFromServer = checkPremium();
    if (resultFromServer == "1"){
        ui->getPremium->setVisible(false);
    }
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
    addToMainTable(searchSetByCar(search));
    ui->SearchLineCar->clear();

    update_statistic();
}

void MainWindow::on_ButtonByTrack_clicked()
{
    QString search = ui->SearchLineTrack->text();
    qDebug() << search;
    addToMainTable(searchSetByTrack(search));
    ui->SearchLineTrack->clear();
    update_statistic();
}

                                     //ВЫПАДАЮЩЕЕ МЕНЮ
void MainWindow::on_actionBy_car_triggered()
{
    QString search = QInputDialog::getText(0, "Search", "Car:",QLineEdit::Normal);
    qDebug() << search;
    addToMainTable(searchSetByCar(search));

    update_statistic();
}

void MainWindow::on_actionBy_Track_triggered()
{
    QString search = QInputDialog::getText(0, "Search", "Track:", QLineEdit::Normal);
    qDebug() << search;
    addToMainTable(searchSetByTrack(search));

    update_statistic();

}
                                    //ВСЕ

void MainWindow::on_pushButton_clicked()
{
    update_statistic();
    addToMainTable(getAllSetups(checkPremium()));
}




//СТАТИСТИКА

void MainWindow::on_ButtonStat_clicked()
{
    MainWindow::setInfo(getInformation());
    qDebug() << MainWindow::info;
    Information info;
    info.setModal(true);
    info.exec();

}


//ЗАГРУЗКА

void MainWindow::on_uploadButton_clicked()
{
    upload UploadWindow;
    UploadWindow.setModal(true);
    UploadWindow.exec();

}




void MainWindow::on_getPremium_clicked()
{
    QMessageBox temp;
    QString resultFromServer = getPrem();
    if (resultFromServer == "true"){
        temp.setText("Премиум доступ успешно получен");
        ui->getPremium->setVisible(false);

    } else temp.setText("Что-то пошло не так");
    temp.exec();
}


