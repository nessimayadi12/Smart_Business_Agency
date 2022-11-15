#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"mission.h"
#include <QMainWindow>
#include "stat_combo.h"
#include "map.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_modifier_clicked();
    void on_pb_PDF_clicked();
    void on_tab_mission_activated(const QModelIndex &index);
    void on_Tri_clicked();
    void on_Tri_2_clicked();
    void on_le_id_supp_textChanged(const QString &arg1);

    void on_stat_clicked();

    void on_map_clicked();

private:
    Ui::MainWindow *ui;
    Mission M1;
    Mission M;
    stat_combo *s;
    Map *m;

};

#endif // MAINWINDOW_H
