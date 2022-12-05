#ifndef STAT_TRANSPORT_H
#define STAT_TRANSPORT_H


#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>

#include <QWidget>

namespace Ui {
class stat_transport;
}

class  stat_transport : public QDialog
{
    Q_OBJECT

public:
    explicit stat_transport(QWidget *parent = nullptr);
    void make_moytransport();

    ~stat_transport();

private:
    Ui::stat_transport *ui;
};

#endif // STAT_TRANSPORT_H
