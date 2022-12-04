#ifndef GESTION_MISSIONS_H
#define GESTION_MISSIONS_H

#include <QWidget>
#include "partenaire.h"


namespace Ui {
class gestion_partenaire;
}

class gestion_partenaire : public QWidget
{
    Q_OBJECT

public:
    explicit gestion_partenaire(QWidget *parent = nullptr);
    ~gestion_partenaire();

private slots:


    void on_pushButton_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_supprimer_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_recherche_textChanged(const QString &arg1);

    void on_pushButton_pdf_clicked();

    void on_pushButton_stat_clicked();

    void on_pushButton_excel_clicked();

private:
    Ui::gestion_partenaire *ui;
    partenaire p;

};

#endif // GESTION_MISSIONS_H
