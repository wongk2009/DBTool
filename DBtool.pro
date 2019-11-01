#-------------------------------------------------
#
# Project created by QtCreator 2019-10-22T22:12:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DBtool
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    modelex.cpp \
    dbtableview.cpp \
    itemeditdelegate.cpp

HEADERS  += mainwindow.h \
    modelex.h \
    dbtableview.h \
    itemeditdelegate.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons.qrc
