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
    void test_case1();
    void test_case_searchByCar();
};

testFuncforserver::testFuncforserver()
{
    DataBase::getInstance("DataBaseTest.db");
}

testFuncforserver::~testFuncforserver()
{

}
//"R8|Monza|https://drive.google.com/uc?export=download&confirm=no_antivirus&id=1ySOMcizxmStDZeCUc72DGGI4RyjEOSbf|R8 Monza|admin|0|1:48.2|0}McLaren|Spa|https://www.youtube.com/watch?v=dQw4w9WgXcQ|dasdada|Artem|0||0}BMW|Spa|https://www.youtube.com/watch?v=3nekHARk3jA|BMW Spa|Artem|0||0}Bentley|Imola|https://www.youtube.com/watch?v=bgbH4FAmAA0|Bentley Imola|NoName|0||0}5|551|5|15|Artem|0|00:00.0|0}"
void testFuncforserver::test_case1()
{
    QCOMPARE("True", auth("Artem", "123"));
}

void testFuncforserver::test_case_searchByCar()
{
    QCOMPARE("R8|Monza|https://drive.google.com/uc?export=download&confirm=no_antivirus&id=1ySOMcizxmStDZeCUc72DGGI4RyjEOSbf|R8 Monza|admin|0|1:48.2|0}", searchByCar("R8", "0"));
    QCOMPARE("", searchByCar("R9", "0"));
    QCOMPARE("", searchByCar("Aston Martin","0"));
}


QTEST_APPLESS_MAIN(testFuncforserver)

#include "tst_testfuncforserver.moc"
