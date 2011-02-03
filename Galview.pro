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
    galfile.cpp \
    chipplotter.cpp \
    spotgraphicsitem.cpp \
    blockgraphicsitem.cpp \
    spot.cpp \
    block.cpp \
    chipview.cpp

HEADERS  += mainwindow.h \
    galfile.h \
    chipplotter.h \
    spotgraphicsitem.h \
    blockgraphicsitem.h \
    spot.h \
    block.h \
    chipview.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

symbian {
    TARGET.UID3 = 0xec4cceee
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}
