/*!
 * \file
 */

#include "functionsforserver.h"
#include <QStringList>

/*!
 * \brief parsing - функция, которая по введённому названию комманды и дополнительным параметрам запускает команду и возращает
 * результат работы.
 * \param [in] data_from_client - строка, которая приходит от клиента в формате func&param1&param2...paramN.
 * \return возвращает результат работы команды, поданной на вход.
*/
QByteArray parsing(QString data_from_client){
    /* data_from_client = NameOfFunc&Param1&Param2&Param3
    * Цель парсинга:
    * return NameOfFunc(Param1&Param2&Param3)
    */
    QStringList data_from_client_list = data_from_client.split(QLatin1Char('&'));

    QString nameOfFunc = data_from_client_list.front();
    data_from_client_list.pop_front();

    if (nameOfFunc == "auth"){
        return auth(data_from_client_list.at(0), data_from_client_list.at(1));}
    else if (nameOfFunc == "reg"){
        return reg(data_from_client_list.at(0), data_from_client_list.at(1), data_from_client_list.at(2));
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
    return "auth done\n";
}

/*!
 * \brief reg - функция, которая реализует команду reg, нужная для регистрации пользователя на сервере.
 * \param [in] log - строка, которая содержит логин пользователя.
 * \param [in] pass - строка, которая содержит пароль пользователя.
 * \param [in] mail - строка, которая содержит необязательный электронный адрес почты пользователя.
 * \return возвращает результат регистрации.
*/
QByteArray reg(QString log, QString pass, QString mail){
    return "reg done\n";
}
