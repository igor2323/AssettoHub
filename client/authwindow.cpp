#include "authwindow.h"
#include "ui_authwindow.h"




AuthWindow::AuthWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthWindow)
{
    ui->setupUi(this);
    ui->regEnterButton->setVisible(false);
    ui->regLabel->setVisible(false);
    ui->regLoginButton->setVisible(false);
    ui->passLoginFormat->setText("Логин и пароль не должны содержать пробелы");
}

AuthWindow::~AuthWindow()
{
    delete ui;
}

void AuthWindow::on_authRegButton_clicked()
{
    ui->authEnterButton->setVisible(false);
    ui->authLabel->setVisible(false);
    ui->authRegButton->setVisible(false);

    ui->regEnterButton->setVisible(true);
    ui->regLabel->setVisible(true);
    ui->regLoginButton->setVisible(true);
}


void AuthWindow::on_regLoginButton_clicked()
{
    ui->authEnterButton->setVisible(true);
    ui->authLabel->setVisible(true);
    ui->authRegButton->setVisible(true);

    ui->regEnterButton->setVisible(false);
    ui->regLabel->setVisible(false);
    ui->regLoginButton->setVisible(false);
}


void AuthWindow::on_authEnterButton_clicked()
{
    QString log = ui->loginInput->text();
    QString pass = ui->passwordInput->text();

    if (log.contains(" ") || pass.contains(" ")){
        QMessageBox space_auth;
        space_auth.setText("Сheck the input condition");
        space_auth.exec();
    } else{
        loginOfUser = log;
        QString resultFromServer = auth(log, pass);
        if (resultFromServer == "True"){
            auth(log,pass);
            emit send_data(log);
            hide();
    }
        else{
            QMessageBox notcorrect;
            notcorrect.setText("Неверный логин или пароль");
            notcorrect.exec();
    }
    }
}


void AuthWindow::on_regEnterButton_clicked()
{
    QString log = ui->loginInput->text();
    QString pass = ui->passwordInput->text();
    if (log.contains(" ") || pass.contains(" ")){
        QMessageBox space_reg;
        space_reg.setText("Сheck the input condition");
        space_reg.exec();
    } else {

        QString resultFromServer = reg(log, pass);

        if (resultFromServer == "True"){
        reg(log,pass);
        emit send_data(log);
        hide();
    }
        else if (resultFromServer == "AlreadyCreated"){
            QMessageBox notcorrect;
            notcorrect.setText("Данный пользователь уже существует");
            notcorrect.exec();

        }
        else if (resultFromServer=="EmptyField"){
            QMessageBox notcorrect;
            notcorrect.setText("Проверьте введённые данные");
            notcorrect.exec();
    }
        else{
            QMessageBox notcorrect;
            notcorrect.setText("Что-то пошло не так");
            notcorrect.exec();
        }
    }
}


