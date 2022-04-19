#include "functions_for_client.h"

void auth(QString log, QString pass){
    QString res = "auth&" + log + "&" + pass + "&";
//    qDebug() << res;
    Client::send_request_to_server(res);
}

void reg(QString log, QString pass){
    QString res = "reg&" + log + "&" + pass + "&";
//    qDebug() << res;
    Client::send_request_to_server(res);
}

void update_statistic(QString log){
    QString res = "updatestat&" + log + "&";
    qDebug() << res;
    Client::send_request_to_server(res);

}

void check_statistic(QString log){
    QString res = "checkstat&" + log + "&";
    qDebug() << res;
    Client::send_request_to_server(res);
}

void searchSetByCar(QString car){
    QString res = "searchByCar&" + car + "&";
    qDebug() << res;
    Client::send_request_to_server(res);
}

void searchSetByTrack(QString track){
    QString res = "searchByTrack&" + track + "&";
    qDebug() << res;
    Client::send_request_to_server(res);
}

