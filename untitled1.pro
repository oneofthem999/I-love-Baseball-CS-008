#-------------------------------------------------
#
# Project created by QtCreator 2017-06-02T06:53:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = untitled1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    editstad.cpp \
    error.cpp \
    item.cpp \
    souvenir.cpp \
    stadium.cpp \
    stadiumgraph.cpp \
    stadiumslist.cpp \
    shoppingcart.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    login.h \
    editstad.h \
    error.h \
    binarytree.h \
    item.h \
    souvenir.h \
    stadium.h \
    stadiumgraph.h \
    stadiumslist.h \
    shoppingcart.h \
    dialog.h

FORMS    += mainwindow.ui \
    login.ui \
    editstad.ui \
    error.ui \
    shoppingcart.ui \
    dialog.ui

OTHER_FILES += \
    Stadiums by index.txt \
    Stadiums.txt
