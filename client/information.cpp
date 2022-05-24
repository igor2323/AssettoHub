#include "information.h"
#include "ui_information.h"

Information::Information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Information)
{
    ui->setupUi(this);

    QString allInformationAboutAccount = MainWindow::getInfo();
    QStringList allInformationAboutAccount_list = allInformationAboutAccount.split("|");
    ui->login->setText("Your username: " + allInformationAboutAccount_list.at(0));
    ui->searchCount->setText("Total number of searches: " + allInformationAboutAccount_list.at(1));
    ui->uploadCount->setText("Number of uploaded settings: " + allInformationAboutAccount_list.at(2));
    if (allInformationAboutAccount_list.at(3) == "1"){
        ui->premium->setText("Account status: Premium");
    } else ui->premium->setText("Account status: Standart");
}

Information::~Information()
{
    delete ui;
}

void Information::on_pushButton_clicked()
{
    close();
}

