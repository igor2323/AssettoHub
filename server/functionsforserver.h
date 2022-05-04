#ifndef FUNCTIONSFORSERVER_H
#define FUNCTIONSFORSERVER_H
#include "database.h"
#include <QString>
#include <QStringList>


QByteArray parsing(QString data_from_client, int socketDesc);
QByteArray auth(QString login, QString pass);
QByteArray reg(QString login, QString pass, int socketDesc);
QByteArray checkStat(int socketDesc);
QByteArray searchByTrack(QString Track);
QByteArray searchByCar(QString car);
QByteArray allSetups();
QByteArray change_sock_desc(QString login, int sock_desc);
#endif // FUNCTIONSFORSERVER_H
