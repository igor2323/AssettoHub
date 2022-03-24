#include <QCoreApplication>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString path = "/home/igor/prom/projects/AssettoHub/database/";
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path+"TestDB.db");

    if(!db.open())
        qDebug()<<db.lastError().text();

    // добавить запись путем SQL запроса
    // создать запрос к БД
   /*
    создание таблицы

    Название: User
    Поля: login, password, status - хранятся значениия типа char[20]
                                         (массив символов длины 20)

    CREATE TABLE User(login VARCHAR(20) NOT NULL, password VARCHAR(20) NOT NULL, status VARCHAR(20) NOT NULL)

    Зачем нужны типы данных?
        Пример: в поле age типа INTEGER в разных записях БД (строках таблицы) записано
                "123"
                34
                "a"
        Вопрос: как сравнивать? преобразуем к заданному типу INTEGER:
                    "123" -> 123
                    34 -> 34
                    "a" -> 65 (код символа)

    Вставить запись в таблицу

    Название таблицы: User
    login: "admin"
    password: "123"

    INSERT INTO User(login, password) VALUES ("admin", "123")
*/
    QSqlQuery query(db);
    query.exec("CREATE TABLE User("
               "login VARCHAR(20) NOT NULL, "
               "password VARCHAR(20) NOT NULL"
               ")");

    //добавить запись в таблицу
    /*query.prepare("INSERT INTO User(login, password) "
                  "VALUES (\"admin\", \"123\")");

*/
    query.prepare("INSERT INTO User(login, password) "
                      "VALUES (:login, :password)");

    query.bindValue(":password","admin123");
    query.bindValue(":login","admin");

    query.exec();

    query.prepare("INSERT INTO User(login, password) "
                      "VALUES (:login, :password)");

    query.bindValue(":password","user123");
    query.bindValue(":login","user");

    query.exec();

    query.prepare("INSERT INTO User(login, password) "
                      "VALUES (:login, :password)");

    query.bindValue(":password","test123");
    query.bindValue(":login","test");

    query.exec();

    /*
    Выбрать все записи БД
    SELECT * FROM User

    Выбрать все записи БД с условием
    SELECT * FROM User WHERE .......
   */

    query.exec("SELECT password FROM User");
    QSqlRecord rec = query.record();
    const int passwordIndex = rec.indexOf("password");

    while(query.next())
        qDebug()<<"\t"<<query.value(passwordIndex)<<"\n";


    query.exec("SELECT login FROM User");
    QSqlRecord recUser = query.record();
    const int loginIndex = recUser.indexOf("login");

    while(query.next())
        qDebug()<<query.value(loginIndex).toString();

    //query.exec("DROP DATABASE Test");
//    query.exec("DROP TABLE User");
    db.close();
    return a.exec();
}
