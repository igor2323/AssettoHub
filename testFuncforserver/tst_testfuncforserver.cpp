#include <QtTest>
#include "/home/igor/prom/projects/AssettoHub/server/functionsforserver.h"
// add necessary includes here

DataBase * DataBase::dataBasePointer;
DataBaseDestroyer DataBase::destroyer;
QSqlDatabase DataBase::db;

class testFuncforserver : public QObject
{
    Q_OBJECT

public:
    testFuncforserver();
    ~testFuncforserver();

private slots:
    void test_case1();

};

testFuncforserver::testFuncforserver()
{
    DataBase::getInstance("DataBaseTest.db");
}

testFuncforserver::~testFuncforserver()
{

}

void testFuncforserver::test_case1()
{
    QCOMPARE("True", auth("Artem", "123"));
}

QTEST_APPLESS_MAIN(testFuncforserver)

#include "tst_testfuncforserver.moc"
