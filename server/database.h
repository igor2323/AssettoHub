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






        static int Test1() {
            return 1;
        };
        static QByteArray getAllSetups(){
            QByteArray result;
            db.open();
            QSqlQuery query;
            query.exec("SELECT * FROM Setup");
            while(query.next()){
                 result.append(query.value(0).toString());
                 result.append("|");
                 result.append(query.value(1).toString());
                 result.append("|");
                 result.append(query.value(2).toString());
                 result.append("|");
                 result.append(query.value(3).toString());
                 result.append("/");
            }
            db.close();
            query.clear();
            qDebug() << result;
            return result;
        }


        static QByteArray checkStat(QString log){
            QByteArray result;
            db.open();
            QSqlQuery query;
            query.exec("SELECT statistics FROM Users WHERE login = 'Artem'");
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
            query.exec("UPDATE Users SET statistics=statistics+1 WHERE login='Artem'");

            //query.exec("UPDATE Users SET statistics=statistics+1 WHERE login=:log");
            //query.bindValue(":log", log);

            db.close();
            query.clear();
            return result;
           }


        static QByteArray searchingSetupByCar(QString car){
            QByteArray result;
            db.open();
            QSqlQuery query;
            query.prepare("SELECT * FROM Setup WHERE car_name = 'R8'");
            //query.bindValue(":car", car);
            QSqlRecord rec = query.record();
            const int statIndex = rec.indexOf("car_name");

            while(query.next())
                 result.append(query.value(statIndex).toString());
            db.close();
            query.clear();
            return result;
           }


        static QByteArray searchingSetupByTrack(QString track){
            QString result;
            QByteArray r;
            db.open();
            QSqlQuery query;
            query.prepare("SELECT car_name FROM Setup WHERE track_name = 'Monza'");
            //query.bindValue(":track", track);
            query.exec();
            QSqlRecord rec = query.record();
            const int carIndex = rec.indexOf("car_name");

            while(query.next()){
                 result.append(query.value(carIndex).toString());
                qDebug() << query.value(carIndex).toString()   ;
            }
            db.close();
            query.clear();
            qDebug() << rec;
            qDebug() << result;
            return r;
           }


        static QByteArray uploadSetup(QString car, QString track, QString comment, QString link){
            QByteArray result;
            db.open();
            QSqlQuery query;
            query.prepare("INSERT INTO Setup VALUES (:car_name, :track_name, :comment,:link)");
            query.bindValue(":car_name", car);
            query.bindValue(":track_name", track);
            query.bindValue(":comment", comment);
            query.bindValue(":link", link);
            query.exec();
            db.close();
            query.clear();
            return result;
           }

};



#endif // DATABASE_H
