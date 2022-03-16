#ifndef FUNCTIONSFORSERVER_H
#define FUNCTIONSFORSERVER_H
#include <QString>

/*!
 * \brief parsing - функция, котороая по введённому названию и параметрам функции возвращает результат
 * \param [in] data_from_client - строка, которая приходит от клиента в формате func&param1&param2...paramN
 * \return возвращает реальтут работы функкции, поданной на вход
 * \example указать_файл.txt
 */

QByteArray parsing(QString data_from_client);

QByteArray auth(QString login, QString pass);
QByteArray reg(QString login, QString pass, QString mail);

#endif // FUNCTIONSFORSERVER_H
