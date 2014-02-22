#-------------------------------------------------
#
# Project created by QtCreator 2014-01-22T17:12:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Univ-Nav
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mapview.cpp \
    pointitem.cpp \
    lineitem.cpp \
    toolview.cpp \
    batiment.cpp \
    etage.cpp \
    salle.cpp \
    portesalle.cpp \
    acces.cpp \
    firstwindow.cpp \
    batimentwindow.cpp \
    etagewindow.cpp

HEADERS  += mainwindow.h \
    mapview.h \
    pointitem.h \
    lineitem.h \
    toolview.h \
    batiment.h \
    etage.h \
    salle.h \
    portesalle.h \
    acces.h \
    firstwindow.h \
    batimentwindow.h \
    etagewindow.h

FORMS    += \
    ../mainwindow.ui \
    firstwindow.ui \
    batimentwindow.ui \
    etagewindow.ui

RESOURCES += \
    ressource.qrc

OTHER_FILES +=
