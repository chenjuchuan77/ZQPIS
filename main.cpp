#include "forminit.h"
#include <QApplication>
#include "comm/accessdb.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FormInit w;
    w.showFullScreen();//此方法只对顶级窗口有效，对子窗口无效
    return a.exec();
}
