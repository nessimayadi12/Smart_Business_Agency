#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <connection.h>
#include <QMainWindow>
#include"partenaire.h"
#include <arduino.h>
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
    void on_pushButton_clicked();

   void on_pushButton2_clicked();

   void on_pushButton_2_clicked();

   void on_radioButton_clicked();

   void on_radioButton_2_clicked();

   void on_radioButton_3_clicked();

   void on_mail_3_textChanged(const QString &arg1);

   void on_pushButton_4_clicked();

   void on_ol1_clicked();

   void on_pushButton_5_clicked();

   void on_mail_3_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::MainWindow *ui;
    partenaire ETMP;
       Arduino A;
};

#endif // MAINWINDOW_H
