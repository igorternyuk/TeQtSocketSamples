#-------------------------------------------------
#
# Project created by QtCreator 2018-05-10T08:41:56
#
#-------------------------------------------------

QT       += core gui network
CONFIG += c++1z
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LocalClient
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.hpp

FORMS    += widget.ui
