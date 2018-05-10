#-------------------------------------------------
#
# Project created by QtCreator 2018-05-09T16:40:28
#
#-------------------------------------------------

QT       += core gui network
CONFIG += c++1z
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LocalServer
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    localserver.cpp

HEADERS  += widget.hpp \
    localserver.hpp

FORMS    += widget.ui
