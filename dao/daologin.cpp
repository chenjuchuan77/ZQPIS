#include "dao/daologin.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>

int DaoLogin::selectCnt(const QVariant &pwd){
    QSqlQuery query;
    QString sql = "select 1 from sys_user where password=?";
    query.prepare(sql);
    query.addBindValue(pwd);
    query.exec();
    return query.record().count();
}
