#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QtSql/QSqlTableModel>
#include <QSqlQuery>
#include <QItemDelegate>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_exitButton_clicked();

    void on_addButton_2_clicked();

    void on_addButton2_2_clicked();

    void on_searshButton_3_clicked();

    void on_searshButton_4_clicked();

    void on_deleteButton_2_clicked();


    void on_showallButton_4_clicked();

    void on_showallButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;
    QSqlTableModel *model2;
    void setTitle();
};
class ReadOnlyDelegate: public QItemDelegate
{
public:
    ReadOnlyDelegate(QWidget *parent = NULL):QItemDelegate(parent)
    {}
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,const QModelIndex &index) const override //final
    {
        Q_UNUSED(parent)
        Q_UNUSED(option)
        Q_UNUSED(index)
        return NULL;
    }
};
#endif // MAINWINDOW_H
