QT += testlib sql
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_testfuncforserver.cpp \
   /home/igor/prom/projects/AssettoHub/server/functionsforserver.cpp

HEADERS += \
    /home/igor/prom/projects/AssettoHub/server/database.h \
    /home/igor/prom/projects/AssettoHub/server/functionsforserver.h \
