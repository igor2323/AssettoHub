#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "functionsforserver.h"

#include <list>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

/*!
* \brief The MyTcpServer class - класс для описания работы сервера
*
* Класс на основе QTcpServer, который ....
*/


class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
public slots:
    void slotNewConnection();
    void slotClientDisconnected();

    void slotServerRead();
private:
    QTcpServer * mTcpServer;
    std::list<QTcpSocket*> mTcpSocket;
    //int server_status;
};
#endif // MYTCPSERVER_H







