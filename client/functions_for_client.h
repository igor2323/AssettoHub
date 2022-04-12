#ifndef FUNCTIONS_FOR_CLIENT_H
#define FUNCTIONS_FOR_CLIENT_H
#include <QString>
#include <QDebug>

void auth(QString log, QString pass);
void reg(QString log, QString pass);
void update_statistic(int n);
int check_statistic();

#endif // FUNCTIONS_FOR_CLIENT_H
