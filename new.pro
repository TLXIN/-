#-------------------------------------------------
#
# Project created by QtCreator 2021-09-07T15:43:11
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = new
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    userwindows.cpp \
    exit.cpp

HEADERS  += mainwindow.h \
    login.h \
    userwindows.h \
    exit.h

FORMS    += mainwindow.ui \
    login.ui \
    userwindows.ui \
    exit.ui
