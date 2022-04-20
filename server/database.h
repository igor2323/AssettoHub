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
        DataBase(){
            db = QSqlDatabase::addDatabase("QSQLITE");
            QString path = "D:/MosPoly/AC_testdb/server/dataBase/";
            db.setDatabaseName(path + "DataBase.db");

            if (!db.open())
                qDebug() << db.lastError().text();
        }
        DataBase(const DataBase&);
        DataBase& operator = (DataBase &);
        ~DataBase() {db.close();}
        friend class DataBaseDestroyer;
    public:
        static DataBase* getInstance(){
            if (!dataBasePointer)
            {
                dataBasePointer = new DataBase();
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
        }

        static QString reg(QString log, QString pass){
            db.open();
            qDebug() << log + " " + pass;
            QSqlQuery query;
            if (log == "" || pass == ""){
                return "EmptyField";
            }
            query.prepare("SELECT * FROM Users where login = :login and password = :password" );
            query.bindValue(":login", log);
            query.bindValue(":password", pass);
            query.exec();
            if (query.next()){
                return "AlreadyCreated";
            }
            else{
                query.prepare("INSERT INTO Users VALUES (:login, :password, 0)" );
                query.bindValue(":login", log);
                query.bindValue(":password", pass);
                query.exec();
                return "True";
            }
            return "Smth went wrong...";
        }






        static QString checkStat(QString log){
            qDebug() << log;
            QByteArray result;
            db.open();
            QSqlQuery query;
            query.prepare("SELECT statistics FROM Users WHERE login = :loginOfUser");
            query.bindValue(":loginOfUser", log);
            query.exec();
            QSqlRecord rec = query.record();
            const int statIndex = rec.indexOf("statistics");

            while(query.next())
                 result.append(query.value(statIndex).toString());

            db.close();
            query.clear();
            return result;
           }


        static QByteArray changeStat(QString log){
            QByteArray result;
            db.open();
            QSqlQuery query;
            query.prepare("UPDATE Users SET statistics=statistics+1 WHERE login=:logOfUser");

            query.bindValue(":logOfUser", log);
            query.exec();
            db.close();
            query.clear();
            return result;
           }

        static QString getAllSetups(){
            QByteArray result;
            db.open();
            QSqlQuery query;
            query.exec("SELECT * FROM Setups");
            while(query.next()){
                 result.append(query.value(0).toString());
                 result.append("|");
                 result.append(query.value(1).toString());
                 result.append("|");
                 result.append(query.value(2).toString());
                 result.append("|");
                 result.append(query.value(3).toString());
                 result.append("}");
            }
            db.close();
            query.clear();
            qDebug() << result;
            return result;
        }

        static QString searchingSetupByCar(QString car){
            QString result;
            db.open();
            QSqlQuery query;
            query.prepare("SELECT * FROM Setups WHERE car_name = :carName");
            query.bindValue(":carName", car);
            query.exec();
            QSqlRecord rec = query.record();
            while(query.next()){
                 result.append(query.value(0).toString());
                 result.append("|");
                 result.append(query.value(1).toString());
                 result.append("|");
                 result.append(query.value(2).toString());
                 result.append("|");
                 result.append(query.value(3).toString());
                 result.append("}");
            }
            db.close();
            query.clear();
            return result + " ";
           }


        static QString searchingSetupByTrack(QString track){
            QString result;
            db.open();
            QSqlQuery query;
            query.prepare("SELECT * FROM Setups WHERE track_name = :trackName");
            query.bindValue(":trackName", track);
            query.exec();
            QSqlRecord rec = query.record();
            while(query.next()){
                 result.append(query.value(0).toString());
                 result.append("|");
                 result.append(query.value(1).toString());
                 result.append("|");
                 result.append(query.value(2).toString());
                 result.append("|");
                 result.append(query.value(3).toString());
                 result.append("}");
            }
            db.close();
            query.clear();
            return result + " ";
           }


        static QByteArray uploadSetup(QString car, QString track, QString comment, QString link){
            QByteArray result;
            db.open();
            QSqlQuery query;
            query.prepare("INSERT INTO Setups VALUES (:car_name, :track_name, :link,:comment)");
            query.bindValue(":car_name", car);
            query.bindValue(":track_name", track);
            query.bindValue(":comment", comment);
            query.bindValue(":link", link);
            query.exec();
            db.close();
            query.clear();
            return result + " ";
           }

};



#endif // DATABASE_H
