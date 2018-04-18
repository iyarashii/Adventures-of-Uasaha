#-------------------------------------------------
#
# Project created by QtCreator 2017-10-26T20:05:04
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Adventures_of_Uasaha
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    pocisk.cpp \
    wrog.cpp \
    gra.cpp \
    punkty.cpp \
    hp.cpp \
    gracz.cpp \
    spawner.cpp \
    menuglowne.cpp \
    pauza.cpp \
    wrog_ranged.cpp \
    wrog_melee.cpp \
    pociskgracza.cpp \
    pociskwroga.cpp \
    boss.cpp \
    millioncheeri.cpp \
    pociskcheeri.cpp \
    hpbossa.cpp \
    rycerz.cpp \
    poziom.cpp \
    sterowanie.cpp

HEADERS += \
    pocisk.h \
    gracz.h \
    wrog.h \
    gra.h \
    punkty.h \
    hp.h \
    gracz.h \
    spawner.h \
    menuglowne.h \
    pauza.h \
    wrog_ranged.h \
    wrog_melee.h \
    pociskgracza.h \
    pociskwroga.h \
    boss.h \
    millioncheeri.h \
    pociskcheeri.h \
    hpbossa.h \
    rycerz.h \
    poziom.h \
    sterowanie.h

RESOURCES += \
    res.qrc

FORMS += \
    menuglowne.ui \
    sterowanie.ui

CONFIG += static
