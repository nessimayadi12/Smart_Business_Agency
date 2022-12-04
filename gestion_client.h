#ifndef GESTION_CLIENT_H
#define GESTION_CLIENT_H

#include <QWidget>
#include "client.h"


namespace Ui {
class gestion_client;
}

class gestion_client : public QWidget
{
    Q_OBJECT

public:
    explicit gestion_client(QWidget *parent = nullptr);
    ~gestion_client();

private slots:

    void on_pb_ajouter_client_clicked();

    void on_pb_supprimer_client_clicked();

    void on_pb_modifier_client_clicked();

    void on_radioButton_cin_clicked();

    void on_radioButton_num_clicked();

    void on_radioButton_date_clicked();

    void on_lineEdit_rech_cin_textChanged(const QString &arg1);

    void on_pb_PDF_client_clicked();

    void on_pb_stat_client_clicked();

    void on_pb_facture_client_clicked();

    void on_pb_whatsapp_client_clicked();

private:
    Ui::gestion_client *ui;
    client etmp;

};

#endif // GESTION_CLIENT_H
