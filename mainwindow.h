#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void sendMail();

    void mailSent(QString);

    void browse();

    void on_modify_clicked(); // modify thezk second window //

    void on_pushButton_clicked(); // add //

    void on_pushButton_2_clicked(); // delete //

    void on_checkBox_stateChanged(int arg1); // checkbox for research employee by id //

    void on_radioButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    Employe g;
    Employe d;
    Employe supp;
    QStringList files;
};

#endif // MAINWINDOW_H
