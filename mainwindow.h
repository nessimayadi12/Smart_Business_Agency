#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "transport.h"
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
    void on_enregistre_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_chercher_clicked();

    void on_afficher_clicked();

    void on_pushButton_qr_clicked();

    void on_pushButton_pdf_clicked();

    void on_pushButton_stat_clicked();

private:
    Ui::MainWindow *ui;
    //Transport T;
};
#endif // MAINWINDOW_H
