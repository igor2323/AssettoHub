#include "upload.h"
#include "ui_upload.h"

#include "QDebug"
#include "QMessageBox"

upload::upload(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::upload)
{
    ui->setupUi(this);
}

upload::~upload()
{
    delete ui;
}

void upload::on_pushButton_clicked()
{
    QString prem;
    if (ui->premToggle->isChecked()){
        prem = "1";
    } else prem = "0";
    QString dataFromServer = uploadSetups(ui->upload_car_name->text(),ui->upload_track_name->text(),ui->upload_comment->text(),ui->upload_link->text(), ui->upload_time->text(), prem);
    if (dataFromServer == "EmptyField"){
        QMessageBox emptyError;
        emptyError.setText("Какое-то поле пустое :c");
        emptyError.exec();
    }
    close();
}

