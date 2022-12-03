#ifndef STAT_ACHREF_H
#define STAT_ACHREF_H

#include <QWidget>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>


namespace Ui {
class stat_achref;
}

class stat_achref : public QWidget
{
    Q_OBJECT

public:
    explicit stat_achref(QWidget *parent = nullptr);
    ~stat_achref();
    void make_logement();

private:
    Ui::stat_achref *ui;
};

#endif // STAT_ACHREF_H
