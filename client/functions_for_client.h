#ifndef FUNCTIONS_FOR_CLIENT_H
#define FUNCTIONS_FOR_CLIENT_H
#include <QString>
#include <QDebug>
#include "client.h"
#include "authwindow.h"

QString auth(QString log, QString pass);
QString reg(QString log, QString pass);

QString check_statistic();

QString searchSetByCar(QString car);
QString searchSetByTrack(QString track);
QString getAllSetups(QString prem);
QString uploadSetups(QString car,QString track, QString comment, QString link, QString time, QString prem);
QString getPrem();
QString checkPremium();
QString getInformation();
void update_statistic();
#endif // FUNCTIONS_FOR_CLIENT_H
