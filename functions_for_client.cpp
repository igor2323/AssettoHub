#include "functions_for_client.h"

void auth(QString log, QString pass){
    QString res = "auth&" + log + "&" + pass + "&";
    qDebug() << res;
    //send_to_server(res)
}

void reg(QString log, QString pass){
    QString res = "reg&" + log + "&" + pass + "&";
    qDebug() << res;
    //send_to_server(res)
}

void update_statistic(int n){
    QString res = "updatestat&" + QString::number(n) + "&";
    qDebug() << res;
    //send_to_server(res)

}

int check_statistic(){
    QString res = "checkstat&";
    qDebug() << res;
    //send_to_server(res)
    return 2; //проверка вывода, потом будет SELECT
}
