#ifndef FUNCTIONSFORSERVER_H
#define FUNCTIONSFORSERVER_H
#include "database.h"
#include <QString>
#include <QStringList>


QByteArray parsing(QString data_from_client);
QByteArray auth(QString login, QString pass);
QByteArray reg(QString login, QString pass);
QByteArray checkStat(QString login);
QByteArray searchByTrack(QString Track);
QByteArray searchByCar(QString car);
#endif // FUNCTIONSFORSERVER_H
