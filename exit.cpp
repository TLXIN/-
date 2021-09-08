#include "exit.h"
#include "ui_exit.h"
#include <QDebug>
#include <QMessageBox>
#include <QByteArray>
#include <QtCore/QChar>
#include <QComboBox>
Exit::Exit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Exit)
{
    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("注册"));
    BG = new QButtonGroup(this);
}

Exit::~Exit()
{
    delete ui;
}

void Exit::on_pushButton_clicked()
{
    QString number = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString password2 = ui->lineEdit_3->text();
    QString name = ui->lineEdit_4->text();
    QString sex;
    QString grade = ui->lineEdit_5->text();
    QSqlQuery query;
    QString n;
    BG->addButton(ui->radioButton,0);
    BG->addButton(ui->radioButton_2,1);
    switch(BG->checkedId()){
    case 0:
        sex = "女";
        break;
    case 1:
        sex = "男";
        break;
    }
    if(!iscard(number))
    {
        QMessageBox::warning(NULL,"注册失败","输入不符合规范");
        qDebug()<<"error1";

    }
    else {
        if(!ispassword(password))
        {
            QMessageBox::warning(NULL,"注册失败","密码输入不规范");
            qDebug()<<"error password";

        }
        else
        {
            if(QString::compare(password,password2)!=0)
            {
                QMessageBox::warning(NULL,"注册失败","两次输入的密码不同");
                qDebug()<<"error password2";

            }
            else
            {
                QString insertstr = QString("insert into users(number,password,name,sex,grade,warning)"
                                            "values('%1','%2','%3','%4','%5','no')").arg(number)
                        .arg(password).arg(name).arg(sex).arg(grade);
                qDebug()<<insertstr;
                qDebug()<<"error";
                if(number!=NULL&&password!=NULL&&name!=NULL&&sex!=NULL&&grade!=NULL)
                {
                    if(isonly(number))
                    {
                        if(query.exec(insertstr)){
                            qDebug()<<"success";
                            QMessageBox::information(NULL,"注册成功","注册成功！",QMessageBox::Ok);
                            this->close();
                        }
                        else
                            QMessageBox::warning(NULL,"注册失败","注册失败，请稍后重试！");
                    }
                    else
                    {
                        QMessageBox::warning(NULL,"注册失败","该用户已存在！");
                    }
                }
                else
                {
                    QMessageBox::warning(NULL,"注册失败","信息不能为空！");
                }
            }

        }
    }


}
bool Exit::iscard(QString &str)
{
    bool result;
    int cont = str.count(),count_n = 0;
    for(int i = 0;i<cont;i++)
    {
        QChar qchr = str.at(i);
        if(qchr.isDigit())
        {
            cont++;
        }
    }
    if(cont==4)
        result =  true;
    else
        result = false;
    return result;

}

bool Exit::isonly(QString str)
{
    QString sql = QString("select * from users where number = '%1'").arg(str),n;
    QSqlQuery query;
    bool result;
    query.exec(sql);
    while(query.next())
    {
        n = query.value(1).toString();
    }
    if(n==NULL)
        result = true;
    else
        result = false;
}
bool Exit::ispassword(QString &str)
{
    int count=str.count();
    int count_l=0,count_n=0;
    bool result;
    for(int i=0;i<count;i++){
        QChar qchar=str.at(i);
        if(qchar.isDigit()){
           count_n++;
        }
        else if(qchar.isLetter()){
            count_l++;
        }
    }
    if(count_l!=0&&count_n!=0&&(count_l+count_n==count)&&count>=6&&count<=18)
        result=true;
    else
        result=false;
    return result;
}
//退出槽
void Exit::on_pushButton_2_clicked()
{
    if(!(QMessageBox::information(this,tr("退出"),tr("确认退出吗？"),tr("yes"),tr("no"))))
    {
        this->close();

    }

}



