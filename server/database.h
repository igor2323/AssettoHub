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
        DataBase(){}
        DataBase(const DataBase& );
        DataBase& operator = (DataBase &);
        ~DataBase() {}
        friend class DataBaseDestroyer;
    public:
        static DataBase* getInstance(){
            if (!dataBasePointer)
            {
                dataBasePointer = new DataBase();
                dataBasePointer->db = QSqlDatabase::addDatabase("QSQLITE");
                QString path = "../";
                dataBasePointer->db.setDatabaseName(path + "TestDB.db");

                if (!dataBasePointer->db.open())
                    qDebug() << dataBasePointer->db.lastError().text();



                destroyer.initialize(dataBasePointer);
            }
            return dataBasePointer;
        }

        static int Test1() {
            return 1;
        };
};

DataBase * DataBase::dataBasePointer = nullptr;
DataBaseDestroyer DataBase::destroyer;
#endif // DATABASE_H
