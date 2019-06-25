#ifndef THREADINIT_H
#define THREADINIT_H

#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QThread>

//数据获取线程
class ThreadInit:public QThread
{
    Q_OBJECT
public:
    explicit ThreadInit();
    void run();

    void action();
private:
    QSqlQueryModel *qSqlQueryModel=nullptr;
    QSqlTableModel *qSqlTableModel=nullptr;
signals:
    void sendMsg(QString sMessage);
};
#endif // THREADINIT_H
