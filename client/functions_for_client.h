#ifndef FUNCTIONS_FOR_CLIENT_H
#define FUNCTIONS_FOR_CLIENT_H
#include <QString>
#include <QDebug>
#include "client.h"

void auth(QString log, QString pass);
void reg(QString log, QString pass);
void update_statistic(QString log);
void check_statistic(QString log);
void searchSetByCar(QString car);
void searchSetByTrack(QString track);


#endif // FUNCTIONS_FOR_CLIENT_H
