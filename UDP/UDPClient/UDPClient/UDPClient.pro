#-------------------------------------------------
#
# Project created by QtCreator 2018-05-10T10:16:01
#
#-------------------------------------------------

QT       += core gui network network
CONFIG += c++1z

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UDPClient
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.hpp

FORMS    += widget.ui
