#ifndef UPLOAD_H
#define UPLOAD_H

#include <QDialog>
#include "client.h"
#include "functions_for_client.h"

namespace Ui {
class upload;
}

class upload : public QDialog
{
    Q_OBJECT

public:
    explicit upload(QWidget *parent = nullptr);
    ~upload();

private slots:
    void on_pushButton_clicked();

private:
    Ui::upload *ui;
};

#endif // UPLOAD_H
