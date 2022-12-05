#ifndef GESTION_MISSIONS_H
#define GESTION_MISSIONS_H

#include <QWidget>
#include "mission.h"


namespace Ui {
class gestion_missions;
}

class gestion_missions : public QWidget
{
    Q_OBJECT

public:
    explicit gestion_missions(QWidget *parent = nullptr);
    ~gestion_missions();

private slots:
    void on_pb_ajouter_m_clicked();
    void on_pb_supprimer_m_clicked();
    void on_pb_modifier_m_clicked();
    void on_pb_PDF_m_clicked();
    void on_tab_mission_activated(const QModelIndex &index);
    void on_Tri_m_clicked();
    void on_Tri_m_2_clicked();
    void on_le_id_supp_textChanged(const QString &arg1);

    void on_stat_m_clicked();


    //void test();


    void on_pb_PDF_m_2_clicked();

private:
    Ui::gestion_missions *ui;
    Mission M1;
    Mission M;
    //Map *m;
    //arduino
    //Arduino A;
    QByteArray data; // variable contenant les données reçues

};

#endif // GESTION_MISSIONS_H
