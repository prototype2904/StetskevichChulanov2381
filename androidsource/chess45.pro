#-------------------------------------------------
#
# Project created by QtCreator 2015-05-23T17:32:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chess45
TEMPLATE = app


SOURCES += main.cpp\
    algoritm.cpp \
    bishop.cpp \
    board.cpp \
    figure.cpp \
    king.cpp \
    knight.cpp \
    move.cpp \
    pawn.cpp \
    player.cpp \
    queen.cpp \
    rook.cpp \
    square.cpp \
    test.cpp \
    timer.cpp

HEADERS  += \
    algoritm.h \
    bishop.h \
    board.h \
    figure.h \
    history.h \
    king.h \
    knight.h \
    move.h \
    pawn.h \
    player.h \
    queen.h \
    rook.h \
    square.h \
    test.h \
    timer.h

FORMS    += \
    board.ui

CONFIG += mobility
MOBILITY = 

DISTFILES += \
    squares.txt \
    deployment.pri \
    android/AndroidManifest.xml \
    android/res/values/libs.xml \
    android/build.gradle \
    android/AndroidManifest.xml \
    android/res/values/libs.xml \
    android/build.gradle

RESOURCES += \
    myres.qrc

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

