#include "formmain.h"
#include "ui_formmain.h"

FormMain::FormMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormMain)
{
    ui->setupUi(this);
    //初始界面
    this->setWindowState(Qt::WindowMaximized); //窗口最大化
    this->setAutoFillBackground(true);//背景充满
}

FormMain::~FormMain()
{
    delete ui;
}
