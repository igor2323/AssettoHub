#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    ui->gitLink->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->gitLink->setOpenExternalLinks(true);
    ui->gitLink->setTextFormat(Qt::RichText);
    ui->gitLink->setText("Наш GitHub: <a href=https://github.com/igor2323/AssettoHub/wiki>AssettoHub</a>");

}

about::~about()
{
    delete ui;
}

void about::on_ButtonAboutBack_clicked()
{
    close();
}

