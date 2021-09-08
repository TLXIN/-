#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTableView>
#include <QSqlQuery>
#include <QDebug>
#include "exit.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("番剧(x0x)"));
    model = new QSqlTableModel(this);
    model->setTable("bilibili");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();


    model2 = new QSqlTableModel(this);
    model2->setTable("users");
    model2->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model2->select();

    setTitle();
    ReadOnlyDelegate * readOnlyDelegate = new ReadOnlyDelegate();

    ui->tableView_3->setModel(model);
    ui->tableView_3->verticalHeader()->setVisible(false);
    ui->tableView_3->setItemDelegateForColumn(0, readOnlyDelegate);
    ui->tableView_3->setColumnWidth(4,110);
    ui->tableView_3->setColumnWidth(6,150);

    ui->tableView_4->setModel(model2);
    ui->tableView_4->verticalHeader()->setVisible(false);
    ui->tableView_4->setItemDelegateForColumn(0, readOnlyDelegate);
    ui->tableView_4->setColumnWidth(1,100);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exitButton_clicked()
{
    if(!QMessageBox::information(this,tr("退出"),tr("确认退出？"),tr("yes"),tr("no")))
    {
        this->close();
}
}
//番剧表增加
void MainWindow::on_addButton_2_clicked()
{
    int rownum = model->rowCount();
    model->insertRows(rownum,1);
}
//用户表增加
void MainWindow::on_addButton2_2_clicked()
{
    int rownum = model2->rowCount();
    model2->insertRows(rownum,1);
}

//番剧表查询
void MainWindow::on_searshButton_3_clicked()
{
    QString title = ui->lineEdit_11->text();//番剧名称
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
//用户表查询
void MainWindow::on_searshButton_4_clicked()
{
    QString number = ui->lineEdit_13->text();
    if(number.length()!=0)
        model2->setFilter(QString("number = '%1").arg(number));

}


void MainWindow::on_deleteButton_2_clicked()
{
    int currow = ui->tableView_3->currentIndex().row();
    QString title = model->data(model->index(currow,7)).toString();
    if(title!=" ")
    {
        model->removeRow(currow);
        int ok = QMessageBox::warning(this,tr("删除改行"),tr("确定删除这部番吗>0<"),QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::No)
    {
        model->revertAll();//回滚
    }
    else {
        if(model->submitAll())
        {
            QMessageBox::information(this,"删除成功","删除成功");
        }
        else{
            QMessageBox::warning(this,tr("数据库错误"),tr("数据库错误"));
        }
    }
    }
    else
    QMessageBox::warning(NULL,"删除失败","删除失败");

}


void MainWindow::on_showallButton_4_clicked()
{
    model2->setTable("users");
    setTitle();
    model2->select();
}

void MainWindow::on_showallButton_3_clicked()
{
    model->setTable("bilibili");
    setTitle();
    model->select();
}
void MainWindow::setTitle()
{
    model->setHeaderData(0,Qt::Horizontal,"观看人数");
    model->setHeaderData(1,Qt::Horizontal,"评分");
    model->setHeaderData(2,Qt::Horizontal,"季度番号");
    model->setHeaderData(3,Qt::Horizontal,"弹幕数量");
    model->setHeaderData(4,Qt::Horizontal,"追番人数");
    model->setHeaderData(5,Qt::Horizontal,"观看量");
    model->setHeaderData(6,Qt::Horizontal,"番剧名称");

    model2->setHeaderData(0,Qt::Horizontal,"账号");
    model2->setHeaderData(1,Qt::Horizontal,"密码");
    model2->setHeaderData(2,Qt::Horizontal,"姓名");
    model2->setHeaderData(3,Qt::Horizontal,"性别");
    model2->setHeaderData(4,Qt::Horizontal,"年级");
    model2->setHeaderData(5,Qt::Horizontal,"warning");



}
