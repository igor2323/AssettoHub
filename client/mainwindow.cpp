#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    ui->label->setText(log);
    show();
}
