#include "mainwindow.h"
#include <QApplication>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <iostream>
#include "login.h"
int main(int argc, char *argv[])
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");//连接本地数据库
    db.setPort(3306);//数据库端口号
    db.setDatabaseName("lib");//数据库名称
    db.setUserName("root");//用户名
    db.setPassword("ylxin2001");//密码
    db.open();//连接数据库
    db.exec("SET NAMES 'GBK'");
    if(!db.open())
        {
            qDebug()<<"不能连接"<<"connect to mysql error"<<db.lastError().text();
        }
        else
        {
             qDebug()<<"连接成功"<<"connect to mysql OK";
        }
    QApplication a(argc, argv);
    login w;
    w.show();

    return a.exec();
}
