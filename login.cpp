#include "login.h"
#include "ui_login.h"
#include <QSqlQuery>
#include <QDebug>
#include <QLineEdit>
#include <mainwindow.h>
#include "userwindows.h"
#include <QMessageBox>
#include "exit.h"
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("登录"));
}

login::~login()
{
    delete ui;
}
QString login::number;
int login::id;

//退出按钮
void login::on_pushButton_3_clicked()
{
    if(!(QMessageBox::information(this,tr("退出"),tr("确定是否退出"),tr("yes"),tr("no"))))
       { this->close();}

}


//登录按钮
void login::on_pushButton_clicked()
{
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);//设置输入为圆点
    login::number = ui->lineEdit->text();//获得输入的文本
    QString password = ui->lineEdit_2->text();
    QSqlQuery query;
    if(login::number.length()!=0&&password.length()!=0)
    {
        //将将要执行的SQL语句存入缓冲区中执行
        QString insert = QString("select password from users where number = '%1'").arg(login::number);
        //判断密码是否正确
        query.exec(insert);
        //执行SQL语句
        while(query.next())
        {
            if(login::number == "4444"&&password == "1111")
            {
                this->close();//关闭
                MainWindow* w = new MainWindow();
                w->show();
                break;
            }
            else if(login::number!="4444"&&query.value(0).toString() == password)
            {
                this->close();
                Userwindows * u = new Userwindows();
                u->show();
                break;
            }
                else{
                QMessageBox::information(this,"登录失败","用户名或密码错误");
                break;
            }
        }

}
}
//注册按钮
void login::on_pushButton_2_clicked()
{
    Exit* w = new Exit();
    w->show();

}
