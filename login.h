/*
#ifndef LOGIN_H
#define LOGIN_H
#include"mission.h"

#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);

    void setmission(Mission M);
    ~login();

private slots:

    void on_pushButton_2_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
*/
