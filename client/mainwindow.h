#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QString>
#include <QInputDialog>




#include "QMessageBox"
#include <QPixmap>


#include "client.h"


#include "about.h"
#include "authwindow.h"
#include "upload.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    AuthWindow *ui_auth;



private slots:
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


};
#endif // MAINWINDOW_H
