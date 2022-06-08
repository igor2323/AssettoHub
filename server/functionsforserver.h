#ifndef FUNCTIONSFORSERVER_H
#define FUNCTIONSFORSERVER_H
#include "database.h"
#include <QString>
#include <QStringList>


QByteArray parsing(QString data_from_client, int socketDesc);

QByteArray auth(QString login, QString pass);
QByteArray reg(QString login, QString pass, int socketDesc);
QByteArray deleteUser(QString log);
QByteArray change_sock_desc(QString login, int sock_desc);

QByteArray checkStat(int socketDesc);

QByteArray searchByTrack(QString Track, QString prem);
QByteArray searchByCar(QString car, QString prem);
QByteArray allSetups(QString prem);

QByteArray uploadSetup(QString car,QString track, QString comment, QString link, QString author, QString time, QString prem, int sock_desc);

QByteArray getPrem(int sock_desc);
QByteArray checkPrem(int sock_desc);

QByteArray getInformation(int sock_desc);
#endif // FUNCTIONSFORSERVER_H
