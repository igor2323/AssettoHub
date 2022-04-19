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
    QString res = "uploadSetup&" + ui->upload_car_name->text() + "&" + ui->upload_track_name->text() + "&" + ui->upload_comment->text() + "&" + ui->upload_link->text() + "&";
    qDebug() << res;
    Client::send_request_to_server(res);
    close();
}

