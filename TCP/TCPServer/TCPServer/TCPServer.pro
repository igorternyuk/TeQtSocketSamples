#-------------------------------------------------
#
# Project created by QtCreator 2018-05-10T09:32:48
#
#-------------------------------------------------

QT       += core gui network
CONFIG += c++1z
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TCPServer
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    tcpserver.cpp

HEADERS  += widget.hpp \
    tcpserver.hpp

FORMS    += widget.ui
