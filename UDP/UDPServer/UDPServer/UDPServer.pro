#-------------------------------------------------
#
# Project created by QtCreator 2018-05-10T10:15:33
#
#-------------------------------------------------

QT       += core gui network
CONFIG += c++1z
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UDPServer
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.hpp

FORMS    += widget.ui
