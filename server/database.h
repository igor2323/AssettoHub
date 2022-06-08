#pragma once
#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

class DataBase;

class DataBaseDestroyer
{
    private:
        DataBase * dataBasePointer;
    public:
        ~DataBaseDestroyer() {delete dataBasePointer;}
        void initialize(DataBase * p){dataBasePointer = p;}
};

class DataBase
{
    private:
        static DataBase * dataBasePointer;
        static DataBaseDestroyer destroyer;
        static QSqlDatabase db;
    protected:
        DataBase(QString db_name){
            db = QSqlDatabase::addDatabase("QSQLITE");
           QString path = "..//server/dataBase/";
            db.setDatabaseName(path + db_name);//

            if (!db.open())
                qDebug() << db.lastError().text();
        }
        DataBase(const DataBase&);
        DataBase& operator = (DataBase &);
        ~DataBase() {db.close();}
        friend class DataBaseDestroyer;
    public:
        static DataBase* getInstance(QString db_name = "DataBase.db"){
            if (!dataBasePointer)
            {
                dataBasePointer = new DataBase(db_name);
                destroyer.initialize(dataBasePointer);
            }
            return dataBasePointer;
        }






//        static int Test1() {
//            return 1;
//        };

        static QString auth(QString log, QString pass){
            db.open();
            qDebug() << log + " " + pass;
            QSqlQuery query;
            query.prepare("SELECT * FROM Users where login = :login and password = :password" );
            query.bindValue(":login", log);
            query.bindValue(":password", pass);
            query.exec();
            if (query.next()){
                return "True";
            }
            else return "False";
            qDebug() << db.lastError().text();
        }

        static QString reg(QString log, QString pass, int socketDesc){
            db.open();
            qDebug() << log + " " + pass;
            QSqlQuery query;
            if (log == "" || pass == ""){
                return "EmptyField";
            }
            query.prepare("SELECT * FROM Users where login = :login" );
            query.bindValue(":login", log);
            query.bindValue(":password", pass);
            query.exec();
            if (query.next()){
                return "AlreadyCreated";
            }
            else{
                query.prepare("INSERT INTO Users VALUES (:login, :password, 0, :sock, 0,0)" );
                query.bindValue(":login", log);
                query.bindValue(":password", pass);
                query.bindValue(":sock", socketDesc);
                query.exec();
                return "True";
            }
            return "Smth went wrong...";
        }






        static QString checkStat(int socketDesc){
            QByteArray result;
            db.open();
            QSqlQuery query;
            query.prepare("SELECT statistics FROM Users WHERE sock = :socketDesc");
            query.bindValue(":socketDesc", socketDesc);
            query.exec();
            QSqlRecord rec = query.record();
            const int statIndex = rec.indexOf("statistics");

            while(query.next())
                 result.append(query.value(statIndex).toString());

            db.close();
            query.clear();
            return result;
           }


        static QByteArray changeStat(int socketDesc){
            QByteArray result;
            db.open();
            QSqlQuery query;
            query.prepare("UPDATE Users SET statistics=statistics+1 WHERE sock=:socketDesc");

            query.bindValue(":socketDesc", socketDesc);
            query.exec();
            db.close();
            query.clear();
            return result;
           }

        static QString getAllSetups(QString prem){
            QByteArray result;
            db.open();
            QSqlQuery query;
            if (prem == "1"){
            query.exec("SELECT * FROM Setups");
            } else query.exec("SELECT * FROM Setups WHERE premium='0'");
            while(query.next()){
                 result.append(query.value(0).toString());
                 result.append("|");
                 result.append(query.value(1).toString());
                 result.append("|");
                 result.append(query.value(2).toString());
                 result.append("|");
                 result.append(query.value(3).toString());
                 result.append("|");
                 result.append(query.value(4).toString());
                 result.append("|");
                 result.append(query.value(5).toString());
                 result.append("|");
                 result.append(query.value(6).toString());
                 result.append("|");
                 result.append(query.value(7).toString());
                 result.append("}");
            }
            db.close();
            query.clear();
            qDebug() << result;
            return result;
        }

        static QString searchingSetupByCar(QString car, QString prem){
            QString result;
            db.open();
            QSqlQuery query;
            if (prem == "1"){
                query.prepare("SELECT * FROM Setups WHERE car_name=:carName");
            } else query.prepare("SELECT * FROM Setups WHERE car_name=:carName AND premium='0'");
            query.bindValue(":carName", car);
            query.bindValue(":prem", prem);
            query.exec();
            while(query.next()){
                result.append(query.value(0).toString());
                result.append("|");
                result.append(query.value(1).toString());
                result.append("|");
                result.append(query.value(2).toString());
                result.append("|");
                result.append(query.value(3).toString());
                result.append("|");
                result.append(query.value(4).toString());
                result.append("|");
                result.append(query.value(5).toString());
                result.append("|");
                result.append(query.value(6).toString());
                result.append("|");
                result.append(query.value(7).toString());
                result.append("}");
            }
            db.close();
            query.clear();
            return result;
           }


        static QString searchingSetupByTrack(QString track, QString prem){
            QString result;
            db.open();
            QSqlQuery query;
            if (prem == "1"){
                query.prepare("SELECT * FROM Setups WHERE track_name=:trackName");
            } else query.prepare("SELECT * FROM Setups WHERE track_name=:trackName AND premium='0'");
            query.bindValue(":trackName", track);
            query.bindValue(":prem", prem);
            query.exec();
            while(query.next()){
                result.append(query.value(0).toString());
                result.append("|");
                result.append(query.value(1).toString());
                result.append("|");
                result.append(query.value(2).toString());
                result.append("|");
                result.append(query.value(3).toString());
                result.append("|");
                result.append(query.value(4).toString());
                result.append("|");
                result.append(query.value(5).toString());
                result.append("|");
                result.append(query.value(6).toString());
                result.append("|");
                result.append(query.value(7).toString());
                result.append("}");
            }
            db.close();
            query.clear();
            return result;
           }


        static QByteArray uploadSetup(QString car, QString track, QString comment, QString link, QString author, QString estTime, QString prem, int sock_desc){
            QByteArray result;
            db.open();
            QSqlQuery query;
            query.prepare("INSERT INTO Setups VALUES (:car_name, :track_name, :link,:comment, :author, 0, :time, :prem)");
            query.bindValue(":car_name", car);
            query.bindValue(":track_name", track);
            query.bindValue(":comment", comment);
            query.bindValue(":link", link);
            query.bindValue(":author", author);
            query.bindValue(":time", estTime);
            query.bindValue(":prem", prem);
            query.exec();
            query.prepare("UPDATE Users SET upload_count=upload_count+1 WHERE sock=:sock_desc");
            query.bindValue(":sock_desc", sock_desc);
            query.exec();
            db.close();
            query.clear();
            return result;
           }
        static QByteArray change_status(QString log, int sock_desc)
        {
            db.open();
            QSqlQuery query;
            query.prepare("UPDATE Users SET sock=:sock_desc WHERE login=:login");
            query.bindValue(":sock_desc", sock_desc);
            query.bindValue(":login", log);
            query.exec();
            db.close();
            query.clear();
            return "true";
        }
        static QByteArray getPrem(int sock_desc)
        {
            db.open();
            QSqlQuery query;
            query.prepare("UPDATE Users SET premium='1' WHERE sock=:sock_desc");
            query.bindValue(":sock_desc", sock_desc);
            query.exec();
            db.close();
            query.clear();
            return "true";
        }
        static QByteArray checkPrem(int sock_desc)
        {
            db.open();
            QSqlQuery query;
            QByteArray result;
            query.prepare("SELECT premium from Users WHERE sock=:sock_desc");
            query.bindValue(":sock_desc", sock_desc);
            query.exec();
            while(query.next()){
                result.append(query.value(0).toString());
            }
            db.close();
            query.clear();
            qDebug() << result[0];
            return result;
        }
        static QByteArray getInformation(int sock_desc)
        {
            db.open();
            QSqlQuery query;
            QByteArray result;
            query.prepare("SELECT login, statistics, upload_count, premium from Users WHERE sock=:sock_desc");
            query.bindValue(":sock_desc", sock_desc);
            query.exec();
            while(query.next()){
                result.append(query.value(0).toString());
                result.append("|");
                result.append(query.value(1).toString());
                result.append("|");
                result.append(query.value(2).toString());
                result.append("|");
                result.append(query.value(3).toString());
            }
            db.close();
            query.clear();
            return result;
        }
};



#endif // DATABASE_H
