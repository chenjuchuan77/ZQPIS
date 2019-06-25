#include "cglobal.h"
#include "threadwait.h"
#include <QtDebug>
//时钟线程
bool Cglobal::isInitEnd = false;
ThreadWait::ThreadWait()
{

}
void ThreadWait::run()
{
    action();
}
void ThreadWait::action()
{
    int cnt = 0;
    for (;;){
        if(Cglobal::isInitEnd){
            emit sendMsg(QString::number(-1));
            break;
        } else{
            sleep(1);
            cnt++;
            emit sendMsg(QString::number(cnt));
        }
    }
}
