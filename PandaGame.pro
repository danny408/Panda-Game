#-------------------------------------------------
#
# Project created by QtCreator 2017-02-08T21:29:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PandaGame
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp

HEADERS  +=

FORMS    +=

LIBS += -LC:/SFML/lib

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += C:/SFML/include
DEPENDPATH += C:/SFML/include

DISTFILES += \
    Feather.ogg \
    panda.jpg
