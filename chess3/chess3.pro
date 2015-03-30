TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    figure.cpp \
    pawn.cpp \
    knight.cpp \
    queen.cpp \
    bishop.cpp \
    king.cpp \
    rook.cpp \
    square.cpp \
    sqaure.cpp \
    algoritm.cpp \
    game.cpp \
    player.cpp \
    board.cpp

RESOURCES += qml.qrc

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
    sqaure.h \
    algoritm.h \
    ptr_vector.h \
    game.h \
    player.h \
    board.h

OTHER_FILES += \
    squares.txt \
    ../../../Downloads/chessboard_wallpaper_by_piratewithrum-d5cj380.png

FORMS += \
    board.ui
