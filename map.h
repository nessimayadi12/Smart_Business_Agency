#ifndef MAP_H
#define MAP_H
#include <QMainWindow>
#include <QWidget>
#include <QVariant>
namespace Ui {
class Map;
}

class Map : public QWidget
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = nullptr);
    ~Map();

private:
    Ui::Map *ui;
signals:
    void setCenter(QVariant, QVariant);
};

#endif // MAP_H
