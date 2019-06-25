#include "accessdb.h"
#include <QMessageBox>
#include <QtDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlIndex>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlTableModel>

AccessDB::AccessDB(){

}

bool AccessDB::openConnectionPis()
{
    const QString driverPis = "QODBC";
    QSqlDatabase dbPis = QSqlDatabase::addDatabase(driverPis);
    const QString connectPis = "DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=F:/ZQPIS/Code/Data/ZQPis.mdb";
    dbPis.setDatabaseName(connectPis);
    if (!dbPis.open()) {
           QMessageBox::critical(0,QObject::tr("打开异常"),dbPis.lastError().text());
           return false;
    }
    return true;
}

bool AccessDB::openConnectionInit()
{
    const QString driverInit = "QODBC";
    QSqlDatabase dbInit = QSqlDatabase::addDatabase(driverInit);
    const QString connectInit = "DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=F:/ZQPIS/Code/Data/ZQInit.mdb";
    dbInit.setDatabaseName(connectInit);
    if (!dbInit.open()) {
           QMessageBox::critical(0,QObject::tr("打开异常"),dbInit.lastError().text());
           return false;
    }
    return true;
}
