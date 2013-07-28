#-------------------------------------------------
#
# Project created by QtCreator 2012-11-26T10:12:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = skin
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    skinmanager.cpp \
    uicommonframe.cpp \
    example_1.cpp

HEADERS  += widget.h \
    skinmanager.h \
    uicommonframe.h \
    example_1.h

FORMS    += widget.ui \
    uicommonframe.ui \
    example_1.ui

RESOURCES += \
    image.qrc
