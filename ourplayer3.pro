#-------------------------------------------------
#
# Project created by QtCreator 2018-07-17T10:49:01
#
#-------------------------------------------------

QT       += core  gui network multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ourplayer3
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
    ourplayer.cpp \
    mediaplayer.cpp \
    network.cpp \
    playerui.cpp

HEADERS += \
        ourplayer.h

FORMS += \
        ourplayer.ui

DISTFILES += \
    image/play.png \
    image/repeat.png \
    image/shuffle.png \
    image/skip-next-circle.png \
    image/skip-previous-circle.png \
    image/单曲循环.png \
    image/点顺序.png \
    image/暂停.png
