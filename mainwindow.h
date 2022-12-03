#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "clients.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_le_cin_2_textChanged(const QString &arg1);

    void on_pb_ajouter_2_clicked();

    void on_pb_stat_clicked();

    void on_pb_ajouter_3_clicked();

    void on_pb_ajouter_4_clicked();

private:
    Ui::MainWindow *ui;
    clients etmp;



};
#endif // MAINWINDOW_H
