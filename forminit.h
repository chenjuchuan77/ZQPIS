#ifndef FORMINIT_H
#define FORMINIT_H

#include "threadinit.h"
#include "threadwait.h"

#include <QWidget>

namespace Ui {
class FormInit;
}

class FormInit : public QWidget
{
    Q_OBJECT

public:
    //QWidget自带
    explicit FormInit(QWidget *parent = nullptr);
    ~FormInit();
    void paintEvent(QPaintEvent *event);

private:
    Ui::FormInit *ui;

    ThreadWait threadWait;
    ThreadInit *threadInit=nullptr;
public slots:
    void recMsg(QString sMessage);
};

#endif // FORMINIT_H
