#ifndef FUNCTIONS_FOR_CLIENT_H
#define FUNCTIONS_FOR_CLIENT_H
#include <QString>
#include <QDebug>
#include "client.h"

QString auth(QString log, QString pass);
QString reg(QString log, QString pass);

QString check_statistic(QString log);

QString searchSetByCar(QString car);
QString searchSetByTrack(QString track);
QString getAllSetups();


void update_statistic(QString log);
#endif // FUNCTIONS_FOR_CLIENT_H
