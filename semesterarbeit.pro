QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TEMPLATE = app
TARGET = semesterarbeit

SOURCES += main.cpp \
    meinwidget.cpp \
    zeichenfeld.cpp

HEADERS += \
    meinwidget.h \
    zeichenfeld.h
