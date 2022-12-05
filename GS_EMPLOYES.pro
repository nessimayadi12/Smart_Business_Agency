#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------


QT+=sql
QT       += core gui sql network multimedia multimediawidgets charts printsupport widgets axcontainer svg
QT += printsupport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    authentification.cpp \
    client.cpp \
    employe.cpp \
    excel.cpp \
    gestion_client.cpp \
    gestion_missions.cpp \
    gestion_partenaire.cpp \
    gestion_transport.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    menu.cpp \
    mission.cpp \
    modify.cpp \
    partenaire.cpp \
    pdf.cpp \
    qrcode.cpp \
    qrcodegeneratedemo.cpp \
    qrcodegenerateworker.cpp \
    qrwidget.cpp \
    smtp.cpp \
    stat1.cpp \
    stat_achref.cpp \
    transport.cpp

HEADERS += \
    authentification.h \
    client.h \
    employe.h \
    excel.h \
    gestion_client.h \
    gestion_missions.h \
    gestion_partenaire.h \
    gestion_transport.h \
        mainwindow.h \
    connection.h \
    menu.h \
    mission.h \
    modify.h \
    partenaire.h \
    pdf.h \
    qrcode.h \
    qrcodegeneratedemo.h \
    qrcodegenerateworker.h \
    qrwidget.h \
    smtp.h \
    stat1.h \
    stat_achref.h \
    transport.h

FORMS += \
        authentification.ui \
        gestion_client.ui \
        gestion_missions.ui \
        gestion_partenaire.ui \
        gestion_transport.ui \
        mainwindow.ui \
        menu.ui \
        modify.ui \
        pdf.ui \
        stat1.ui \
        stat_achref.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc \
    resources.qrc

DISTFILES +=
