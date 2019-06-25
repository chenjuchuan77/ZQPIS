#ifndef ACCESSDB_H
#define ACCESSDB_H
#include <QtSql>
class AccessDB
{
public:
    AccessDB();
    //静态
    static bool openConnectionPis();
    static bool openConnectionInit();
};
#endif // ACCESSDB_H
