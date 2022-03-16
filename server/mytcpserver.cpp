#include "mytcpserver.h"
#include "functionsforserver.h"
#include <QDebug>
#include <QCoreApplication>
#include <iostream>

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    //server_status=0;
}
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);
    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        //server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
 //   if(server_status==1){
        QTcpSocket *tempSocket;
        tempSocket = mTcpServer->nextPendingConnection();
        mTcpSocket.push_back(tempSocket);
        tempSocket->write("Hello, World!!! I am echo server!\r\n");
        connect(tempSocket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
        connect(tempSocket,&QTcpSocket::disconnected,this, &MyTcpServer::slotServerRead);
   // }
}

void MyTcpServer::slotServerRead(){
    QTcpSocket *tempSock = (QTcpSocket*)sender();
    while(tempSock->bytesAvailable()>0){
                QString str = tempSock->readAll();
                QByteArray array;
                array.append(str);
                tempSock->write(parsing(array));}
}


void MyTcpServer::slotClientDisconnected(){
        QTcpSocket *tempSock = (QTcpSocket*)sender();
        mTcpSocket.remove(tempSock);
        tempSock->close();
}
