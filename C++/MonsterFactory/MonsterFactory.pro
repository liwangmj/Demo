TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    lightmonster.cpp \
    heavymonster.cpp \
    heavymonsterfactory.cpp \
    lightmonsterfactory.cpp

HEADERS += \
    abstractmonsterfactory.h \
    abstractmonstertype.h \
    lightmonster.h \
    heavymonster.h \
    heavymonsterfactory.h \
    lightmonsterfactory.h

