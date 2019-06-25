#include "cglobal.h"
#include "threadinit.h"
#include "comm/accessdb.h"
#include <QtDebug>
#include <bll/blllogin.h>
//读取系统上次保留的结果
ThreadInit::ThreadInit()
{

}
void ThreadInit::run()
{
    action();
}
void ThreadInit::action()
{
    if (!AccessDB::openConnectionPis()){
        return;
    }
    BllLogin bll;
    int cnt = bll.login("123456");
    if(cnt == 1){
        Cglobal::isInitEnd=true;
    }
}
