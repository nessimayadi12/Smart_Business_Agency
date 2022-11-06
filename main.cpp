#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QMessageBox>
#include "employe.h"
#include "connection.h"
#include"modify.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnect();
    MainWindow w;

    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("Employees Management"),
                    QObject::tr("WELCOME\n"
                                "Click OK to enter."), QMessageBox::Ok);
        qDebug() << "zak khobzti fel fifa";
}
    return a.exec();
}
