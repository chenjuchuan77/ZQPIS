#include "forminit.h"
#include "formmain.h"
#include "ui_forminit.h"
#include <QPainter>
#include <unistd.h>

FormInit::FormInit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormInit)
{
    ui->setupUi(this);

    //初始界面
    this->setAutoFillBackground(true);//背景充满

    connect(&threadWait,SIGNAL(sendMsg(QString)),this,SLOT(recMsg(QString)));
    threadWait.start(QThread::HighestPriority);
    threadInit = new ThreadInit();
    connect(threadInit,SIGNAL(sendMsg(QString)),this,SLOT(recMsg(QString)));
    threadInit->start(QThread::LowestPriority);
}

FormInit::~FormInit()
{
    //终止线程
    threadWait.terminate();
    threadInit->terminate();
    threadInit->deleteLater();
    delete ui;
}

void FormInit::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(0,0, this->width(), this->height(), QPixmap(":/img/bg.jpg"));
}

void FormInit::recMsg(QString sMessage){
    if(sMessage=="-1"){
        FormMain *form = new FormMain(this);
        form->setAttribute(Qt::WA_DeleteOnClose);
        //form->setWindowFlags(form->windowFlags() & ~Qt::WindowMaximizeButtonHint& ~Qt::WindowMinimizeButtonHint);
        form->setWindowFlag(Qt::Window,true);//设置为窗口模式
        form->setWindowOpacity(1.0);//透明度
        form->show();
        //终止线程
        threadWait.quit();
        threadWait.wait();
        threadInit->quit();
        threadInit->wait();
        this->hide();
        return;
    }
    ui->lbSecond->setText(sMessage);
}
