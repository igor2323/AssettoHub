/*!
 * \file
 */

#include "functionsforserver.h"


/*!
 * \brief parsing - функция, которая по введённому названию комманды и дополнительным параметрам запускает команду и возращает
 * результат работы.
 * \param [in] data_from_client - строка, которая приходит от клиента в формате func&param1&param2...paramN.
 * \return возвращает результат работы команды, поданной на вход.
*/
QByteArray parsing(QString data_from_client, int socketDesc){
    QStringList data_from_client_list = data_from_client.split(QLatin1Char('&'));
    QString nameOfFunc = data_from_client_list.front();
    data_from_client_list.pop_front();
   // qDebug() << nameOfFunc;

    qDebug() << data_from_client;
    if (nameOfFunc == "auth"){
        change_sock_desc(data_from_client_list.at(0), socketDesc);
        return auth(data_from_client_list.at(0), data_from_client_list.at(1));}

    else if (nameOfFunc == "reg"){
        return reg(data_from_client_list.at(0), data_from_client_list.at(1), socketDesc);}

    else if (nameOfFunc == "getAllSetups"){
        return allSetups(data_from_client_list.at(0));}

    else if (nameOfFunc == "checkstat"){
        return checkStat(socketDesc);}

    else if (nameOfFunc == "updatestat"){
        return DataBase::changeStat(socketDesc);}

    else if (nameOfFunc == "searchByCar"){
        return searchByCar(data_from_client_list.at(0), data_from_client_list.at(1));}

    else if (nameOfFunc == "searchByTrack"){
        return searchByTrack(data_from_client_list.at(0), data_from_client_list.at(1));}

    else if (nameOfFunc == "uploadSetup"){
        return uploadSetup(data_from_client_list.at(0),data_from_client_list.at(1),data_from_client_list.at(2),data_from_client_list.at(3), data_from_client_list.at(4),
                           data_from_client_list.at(5),data_from_client_list.at(6), socketDesc);}

    else if (nameOfFunc == "getPremium"){
        return getPrem(socketDesc);}

    else if (nameOfFunc == "checkPremium"){
        return checkPrem(socketDesc);}

    else if (nameOfFunc == "getInformation"){
        return getInformation(socketDesc);}
    else
        return "error";

}

/*!
 * \brief auth - функция, которая реализует команду auth, нужная для аутентификации пользователя на сервере.
 * \param [in] log - строка, которая содержит логин пользователя.
 * \param [in] pass - строка, которая содержит пароль пользователя.
 * \return возвращает результат аутентификации.
*/
QByteArray auth(QString log, QString pass){
    QByteArray result = "";
    result.append(DataBase::auth(log, pass).toUtf8());
    qDebug() << result;
    return result;
}

/*!
 * \brief reg - функция, которая реализует команду reg, нужная для регистрации пользователя на сервере.
 * \param [in] log - строка, которая содержит логин пользователя.
 * \param [in] pass - строка, которая содержит пароль пользователя.
 * \param [in] mail - строка, которая содержит необязательный электронный адрес почты пользователя.
 * \return возвращает результат регистрации.
*/
QByteArray reg(QString log, QString pass, int socketDesc){
    QByteArray result = "";
    result.append(DataBase::reg(log, pass, socketDesc).toUtf8());
    qDebug() << result;
    return result;
}

QByteArray checkStat(int socketDesc){
    QByteArray result = "";
    result.append(DataBase::checkStat(socketDesc).toUtf8());
    qDebug() << result;
    return result;
}
QByteArray searchByCar(QString car, QString prem){
    QByteArray result = "";
    result.append(DataBase::searchingSetupByCar(car, prem).toUtf8());
    qDebug() << result;
    return result;
}
QByteArray searchByTrack(QString track, QString prem){
    QByteArray result = "";
    result.append(DataBase::searchingSetupByTrack(track, prem).toUtf8());
    qDebug() << result;
    return result;
}
QByteArray allSetups(QString prem){
    QByteArray result = "";
    result.append(DataBase::getAllSetups(prem).toUtf8());
    qDebug() << result;
    return result;
}
QByteArray uploadSetup(QString car,QString track, QString comment, QString link, QString author, QString time, QString prem,int sock_desc){
    QByteArray result = "";
    result.append(DataBase::uploadSetup(car,track, comment,link,author, time, prem,sock_desc));
    qDebug() << result;
    return result;
}
QByteArray change_sock_desc(QString login, int sock_desc)
{
    QByteArray result;
    result.append(DataBase::change_status(login, sock_desc));
    return result;
}
QByteArray getPrem(int sock_desc)
{
    QByteArray result;
    result.append(DataBase::getPrem(sock_desc));
    return result;
}
QByteArray checkPrem(int sock_desc)
{
    QByteArray result;
    result.append(DataBase::checkPrem(sock_desc));
    return result;
}

QByteArray getInformation(int sock_desc)
{
    QByteArray result;
    result.append(DataBase::getInformation(sock_desc));
    return result;
}
