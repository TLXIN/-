#include "userwindows.h"
#include "ui_userwindows.h"
#include <QMessageBox>
#include "mainwindow.h"
#include <QTableView>
#include <QSqlQuery>
#include <QDebug>
Userwindows::Userwindows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Userwindows)
{
    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("新番查询 (0x0)"));
    model = new QSqlTableModel(this);
    model->setTable("bilibili");
    setTitle();
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->verticalHeader()->setVisible(false);

    ui->tableView->setColumnWidth(4,130);
    ui->tableView->setColumnWidth(6,150);
}

Userwindows::~Userwindows()
{
    delete ui;
}
//退出
void Userwindows::on_exitButton_clicked()
{
    if (!(QMessageBox::information(this,tr("退出"),tr("确定退出吗?"),tr("Yes"),tr("No"))))
    {
        this->close();
    }
}
//查询
void Userwindows::on_searchButton_clicked()
{

    QString title = ui->lineEdit->text();//番剧名称
    QSqlQuery query;
    int count = 0;
    if(title.length()!=0)
    {
        model->setFilter(QString("title like '%%1%'").arg(title));
        model->select();
        QString sql = QString("select * from bilibili where title like '%%1%'").arg(title);
        query.exec(sql);
        while(query.next())
        {
            count++;
        }


    }


}

void Userwindows::on_showAllButton_clicked()
{
    model->setTable("bilibili");
    setTitle();
    model->select();
}
void Userwindows::setTitle()
{
    model->setHeaderData(0,Qt::Horizontal,"观看人数");
    model->setHeaderData(1,Qt::Horizontal,"评分");
    model->setHeaderData(2,Qt::Horizontal,"季度番号");
    model->setHeaderData(3,Qt::Horizontal,"弹幕数量");
    model->setHeaderData(4,Qt::Horizontal,"追番人数");
    model->setHeaderData(5,Qt::Horizontal,"观看量");
    model->setHeaderData(6,Qt::Horizontal,"番剧名称");

}
