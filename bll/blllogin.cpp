#include "bll/blllogin.h"

#include <QSqlQuery>

#include <dao/daologin.h>
int BllLogin::login(const QVariant &pwd){
    DaoLogin dao;
    int cnt = dao.selectCnt(pwd);
    return cnt;
}
