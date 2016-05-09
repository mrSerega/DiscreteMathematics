QT += core
QT -= gui

CONFIG += c++11

TARGET = DiscreteMathematics
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    dijkstra.cpp \
    bellmanford.cpp \
    levit.cpp \
    floydwarshall.cpp \
    test.cpp \
    crapalgo.cpp

HEADERS += \
    dijkstra.h \
    bellmanford.h \
    levit.h \
    floydwarshall.h \
    test.h \
    crapalgo.h
