QT += core
QT -= gui

CONFIG += c++11

TARGET = COM_Test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    com_module.cpp

HEADERS += \
    com_module.h
