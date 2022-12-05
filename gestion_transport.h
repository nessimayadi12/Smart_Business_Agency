#ifndef GESTION_TRANSPORT_H
#define GESTION_TRANSPORT_H

#include <QWidget>
#include "transport.h"

namespace Ui {
class gestion_transport;
}

class gestion_transport : public QWidget
{
    Q_OBJECT

public:
    explicit gestion_transport(QWidget *parent = nullptr);
    ~gestion_transport();
    void on_pushButton_ajouter_clicked();

        void on_pushButton_supprimer_clicked();

        void on_pushButton_modifier_clicked();

        void on_pushButton_pdf_clicked();

        void on_pushButton_qr_clicked();

        void on_supprimer_clicked();

        void on_chercher_clicked();

        void on_pushButton_7_clicked();

private slots:
        void on_pushButton_clicked();

        void on_pushButton_qr_2_clicked();

        void on_pushButton_pdf_2_clicked();

        void on_pushButton_qr_3_clicked();

        void on_pushButton_ajouter_2_clicked();

        void on_pushButton_modifier_2_clicked();

        void on_chercher_2_clicked();

        void on_delete_transport_clicked();

        void on_pushButton_afficher_clicked();

        void on_tableView_clicked(const QModelIndex &index);

        void on_id_ch_textChanged(const QString &arg1);

        void on_comboBox_currentIndexChanged(int index);

        void on_pushButton_stat_clicked();

private:
    Ui::gestion_transport *ui;
    transport T;
       transport m;
       transport supp;
       QStringList files;
};

#endif // GESTION_TRANSPORT_H
