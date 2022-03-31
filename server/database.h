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
            QString path = "../";
            db.setDatabaseName(path + "TestDB.db");

            if (!db.open())
                qDebug() << db.lastError().text();
        }
        DataBase(const DataBase& );
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
};



#endif // DATABASE_H
