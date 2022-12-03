/*#include "map.h"
#include<QQuickItem>

Map::Map(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Map)
{
    ui->setupUi(this);
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    ui->quickWidget->show();

    auto obj = ui->quickWidget->rootObject();
    connect(this, SIGNAL(setCenter(QVariant, QVariant)),obj, SLOT(setCenter(QVariant,QVariant)));
    emit setCenter(25.000, 50.000);
}

Map::~Map()
{
    delete ui;
}
*/
