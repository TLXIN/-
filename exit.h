#ifndef EXIT_H
#define EXIT_H

#include <QWidget>
#include <QtSql/QSqlTableModel>
#include <QSqlQuery>
#include <QObject>
#include <QButtonGroup>
namespace Ui {
class Exit;
}

class Exit : public QWidget
{
    Q_OBJECT

public:
    explicit Exit(QWidget *parent = 0);
    static bool ispassword(QString &str);
    static bool iscard(QString &str);
    static bool isonly(QString str);


    ~Exit();
private slots:
//    void on_ExitResultButton_clicked();
//    void on_CloseButton_clicked();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::Exit *ui;
    QButtonGroup *BG;
};

#endif // EXIT_H
