#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "authwindow.h"
#include "QString"

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
};
#endif // MAINWINDOW_H
