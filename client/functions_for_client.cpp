#include "functions_for_client.h"

QString auth(QString log, QString pass){
    QString res = "auth&" + log + "&" + pass + "&";
    return Client::send_request_to_server(res);
}

QString reg(QString log, QString pass){
    QString res = "reg&" + log + "&" + pass + "&";
    return Client::send_request_to_server(res);
}

QString check_statistic(){
    QString res = "checkstat&";
    return Client::send_request_to_server(res);
}


void update_statistic(){
    QString res = "updatestat&";
    qDebug() << res;
    Client::send_request_to_server(res);

}




QString searchSetByCar(QString car){
    QString res = "searchByCar&" + car + "&" + checkPremium() + "&";
    qDebug() << res;
    return Client::send_request_to_server(res);
}

QString searchSetByTrack(QString track){
    QString res = "searchByTrack&" + track + "&" + checkPremium() + "&";
    qDebug() << res;
    return Client::send_request_to_server(res);
}

QString getAllSetups(QString prem){
    QString res = "getAllSetups&" + prem + "&";
    qDebug() << res;
    return Client::send_request_to_server(res);
}

QString uploadSetups(QString car,QString track, QString comment, QString link, QString time, QString prem){
    QString res = "uploadSetup&" + car + "&" + track + "&" + comment + "&" + link + "&" + AuthWindow::getNameOfUser() + "&" + time + "&" + prem + "&";
    qDebug() << res;
    return Client::send_request_to_server(res);
}
QString getPrem(){
    return Client::send_request_to_server("getPremium&");
}
QString checkPremium(){
    return Client::send_request_to_server("checkPremium&");
}

QString getInformation()
{
    return Client::send_request_to_server("getInformation&");
}
