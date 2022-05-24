#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QString>
#include <QInputDialog>
#include <QDesktopServices>



#include "QMessageBox"
#include <QPixmap>


#include "client.h"


#include "about.h"
#include "authwindow.h"
#include "upload.h"
#include "information.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    inline static QString info;

    static void setInfo(QString newInfo){
        info = newInfo;
    }

    static QString getInfo(){
        return info;
    }


    void addToMainTable(QString dataFromServer){
        ui->MainTable->clearContents();
        if (dataFromServer == " "){
            QMessageBox nullBox;
            nullBox.setText("Увы, такого тут нет((");
            nullBox.exec();
        }
        else {

            for ( int i = 0; i < ui->MainTable->rowCount(); ++i )
            {
                ui->MainTable->removeRow(i);
            }
            QStringList bigRecord = dataFromServer.split(QLatin1Char('}'));
            for (int i = 0; i<bigRecord.length(); i++){
                ui->MainTable->setRowCount(ui->MainTable->rowCount()+1);
                QStringList oneRecord = bigRecord[i].split("|");
                for (int j = 0; j<oneRecord.length(); j++){
                    if (j==2){
                        //QPushButton* button = new QPushButton();
                        //button->setProperty("row", i);
                        //connect(button, SIGNAL(clicked()), SLOT(onClicked()));
                        //ui->MainTable->setCellWidget(i, j, button);
                        QLabel *hyperLabel = new QLabel;
                        hyperLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
                        hyperLabel->setOpenExternalLinks(true);
                        hyperLabel->setTextFormat(Qt::RichText);
                        hyperLabel->setText(createHREF(oneRecord[j]));
                        qDebug() << hyperLabel->text();
                        ui->MainTable->setCellWidget(i,j, hyperLabel);
                    }
                    else if (j==6){
                        if (oneRecord.last()=="1"){
                            QTableWidgetItem *item = new QTableWidgetItem(tr("%1").arg(oneRecord[j])+'\t'+"👑");
                            qDebug() << item->text();
                            ui->MainTable->setItem(i,j, item);
                        } else {
                            QTableWidgetItem *item = new QTableWidgetItem(tr("%1").arg(oneRecord[j]));
                            qDebug() << item->text();
                            ui->MainTable->setItem(i,j, item);
                        }
                    }
                    else {
                        QTableWidgetItem *item = new QTableWidgetItem(tr("%1").arg(oneRecord[j]));
                        qDebug() << item->text();
                        ui->MainTable->setItem(i,j, item);
                    }
                }
            }
        }
    };

    QString createHREF(QString link){
        return ("<a href=" + QString(34) + link + QString(34) + ">" + link + "</a>");
    }
private:
    Ui::MainWindow *ui;
    AuthWindow *ui_auth;


private slots:

//    void onClicked() {
//         QPushButton* button = qobject_cast<QPushButton*>(sender());
//         if (!button) return;
//         QVariant var = button->property("row");
//         if (!var.isValid()) return;
//         qDebug() << "row is " << var.toInt();

//    }

    void slot_show(QString log);

    void on_actionExit_triggered(bool checked);
    void on_actionAbout_product_triggered();
    void on_ButtonByCar_clicked();
    void on_ButtonByTrack_clicked();
    void on_ButtonStat_clicked();
    void on_actionBy_car_triggered();
    void on_actionBy_Track_triggered();
    void on_uploadButton_clicked();
    void on_pushButton_clicked();

    void on_getPremium_clicked();
};
#endif // MAINWINDOW_H
