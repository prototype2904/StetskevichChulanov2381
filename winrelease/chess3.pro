TEMPLATE = app

QT += qml quick widgets

INCLUDEPATH +=$$PWD

win32:RC_FILE = chess3.rc

SOURCES += main.cpp \
    figure.cpp \
    pawn.cpp \
    knight.cpp \
    queen.cpp \
    bishop.cpp \
    king.cpp \
    rook.cpp \
    square.cpp \
    algoritm.cpp \
    player.cpp \
    board.cpp \
    timer.cpp \
    move.cpp \
    test.cpp

RESOURCES +=

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    figure.h \
    pawn.h \
    knight.h \
    queen.h \
    bishop.h \
    king.h \
    rook.h \
    square.h \
    algoritm.h \
    player.h \
    board.h \
    timer.h \
    move.h \
    test.h

OTHER_FILES += \
    squares.txt \
    chess3.rc \
    ../../../Downloads/king (4).ico \
    image/figure_black/king.png

FORMS += \
    board.ui
