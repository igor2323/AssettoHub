#include "upload.h"
#include "ui_upload.h"

#include "QDebug"

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
    QString res = "upload&" + ui->upload_car_name->text() + "&" + ui->upload_track_name->text() + "&" + ui->upload_comment->text() + "&" + ui->upload_link->text() + "&";
    qDebug() << res;
    //send
    close();
}

