#include "functions_for_client.h"

QString auth(QString log, QString pass){
    QString res = "auth&" + log + "&" + pass + "&";
    return Client::send_request_to_server(res);
}

QString reg(QString log, QString pass){
    QString res = "reg&" + log + "&" + pass + "&";
    return Client::send_request_to_server(res);
}

QString check_statistic(QString log){
    QString res = "checkstat&" + log + "&";
    return Client::send_request_to_server(res);
}


void update_statistic(QString log){
    QString res = "updatestat&" + log + "&";
    qDebug() << res;
    Client::send_request_to_server(res);

}




QString searchSetByCar(QString car){
    QString res = "searchByCar&" + car + "&";
    qDebug() << res;
    return Client::send_request_to_server(res);
}

QString searchSetByTrack(QString track){
    QString res = "searchByTrack&" + track + "&";
    qDebug() << res;
    return Client::send_request_to_server(res);
}

QString getAllSetups(){
    QString res = "getAllSetups&";
    qDebug() << res;
    return Client::send_request_to_server(res);
}
