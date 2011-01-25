#-------------------------------------------------
#
# Project created by QtCreator 2011-01-24T16:09:05
#
#-------------------------------------------------

QT       += core gui

TARGET = Galview
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    galfile.cpp

HEADERS  += mainwindow.h \
    galfile.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

symbian {
    TARGET.UID3 = 0xec4cceee
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}
