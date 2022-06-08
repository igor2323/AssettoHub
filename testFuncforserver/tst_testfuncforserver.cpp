#include <QtTest>
//#include "/home/igor/prom/projects/AssettoHub/server/functionsforserver.h"
#include "../server/functionsforserver.h"
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
    void test_case_auth();
    void test_case_searchByCar();
    void test_case_reg();
};

testFuncforserver::testFuncforserver()
{
    DataBase::getInstance("DataBaseTest.db");
}

testFuncforserver::~testFuncforserver()
{

}

void testFuncforserver::test_case_reg()
{
    deleteUser("Kostik");
    QCOMPARE("True", reg("Kostik", "kinoman", 1));
    QCOMPARE("EmptyField", reg("", "kinoman", 2));
    deleteUser("Konstantin Kinoman");
    QCOMPARE("False", reg("Konstantin Kinoman", "kinoman", 3));
}

void testFuncforserver::test_case_auth()
{
    QCOMPARE("True", auth("Artem", "123"));
    QCOMPARE("True", auth("igor", "igor"));
    QCOMPARE("False", auth("aaa", "bbb"));
}

void testFuncforserver::test_case_searchByCar()
{
    QCOMPARE("R8|Monza|https://drive.google.com/uc?export=download&confirm=no_antivirus&id=1ySOMcizxmStDZeCUc72DGGI4RyjEOSbf|R8 Monza|admin|0|1:48.2|0}", searchByCar("R8", "0"));
    QCOMPARE("", searchByCar("R9", "0"));
    QCOMPARE("", searchByCar("Aston Martin","0"));
}


QTEST_APPLESS_MAIN(testFuncforserver)

#include "tst_testfuncforserver.moc"
