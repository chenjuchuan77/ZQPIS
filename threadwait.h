#ifndef THREADWAIT_H
#define THREADWAIT_H
#include <QThread>

//时钟线程
class ThreadWait:public QThread
{
    Q_OBJECT
public:
    explicit ThreadWait();
    void run();

    void action();
signals:
    void sendMsg(QString sMessage);
};
#endif // THREADWAIT_H
