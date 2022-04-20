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
QByteArray parsing(QString data_from_client){
    QStringList data_from_client_list = data_from_client.split(QLatin1Char('&'));
    QString nameOfFunc = data_from_client_list.front();
    data_from_client_list.pop_front();
    qDebug() << nameOfFunc;

    if (nameOfFunc == "auth"){
        return auth(data_from_client_list.at(0), data_from_client_list.at(1));}

    else if (nameOfFunc == "reg"){
        return reg(data_from_client_list.at(0), data_from_client_list.at(1));}

    else if (nameOfFunc == "getAllSetups"){
        return DataBase::getAllSetups();}

    else if (nameOfFunc == "checkstat"){
        return checkStat(data_from_client_list.at(0));}

    else if (nameOfFunc == "updatestat"){
        return DataBase::changeStat(data_from_client_list.at(0));}

    else if (nameOfFunc == "searchByCar"){
        return searchByCar(data_from_client_list.at(0));}

    else if (nameOfFunc == "searchByTrack"){
        return searchByTrack(data_from_client_list.at(0));}

    else if (nameOfFunc == "uploadSetup"){
        return DataBase::uploadSetup(data_from_client_list.at(0),data_from_client_list.at(1),data_from_client_list.at(2),data_from_client_list.at(3));

    }else
        return "error\n";

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
QByteArray reg(QString log, QString pass){
    QByteArray result = "";
    result.append(DataBase::reg(log, pass).toUtf8());
    qDebug() << result;
    return result;
}

QByteArray checkStat(QString log){
    QByteArray result = "";
    result.append(DataBase::checkStat(log).toUtf8());
    qDebug() << result;
    return result;
}
QByteArray searchByCar(QString car){
    QByteArray result = "";
    result.append(DataBase::searchingSetupByCar(car).toUtf8());
    qDebug() << result;
    return result;
}
QByteArray searchByTrack(QString track){
    QByteArray result = "";
    result.append(DataBase::searchingSetupByTrack(track).toUtf8());
    qDebug() << result;
    return result;
}
