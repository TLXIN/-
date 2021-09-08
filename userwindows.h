#ifndef USERWINDOWS_H
#define USERWINDOWS_H

#include <QWidget>
#include <QtSql/QSqlTableModel>
namespace Ui {
class Userwindows;
}

class Userwindows : public QWidget
{
    Q_OBJECT

public:
    explicit Userwindows(QWidget *parent = 0);
    ~Userwindows();

private slots:
    void on_exitButton_clicked();

    void on_searchButton_clicked();

    void on_showAllButton_clicked();

private:
    Ui::Userwindows *ui;
    QSqlTableModel *model;
    void setTitle();
};

#endif // USERWINDOWS_H
