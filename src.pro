#
# VLC-Qt Simple Player
# Copyright (C) 2015 Tadej Novak <tadej@tano.si>
#

TARGET      = simple-player
TEMPLATE    = app
CONFIG 	   += c++11

QT         += widgets

SOURCES    += main.cpp \
    SimplePlayer.cpp \
    customvolumeslider.cpp \
    system.cpp \
    customseekslider.cpp \
    fulldialog.cpp \
    listdialog.cpp \
    modules/channel.cpp \
    modules/channelgroup.cpp \
    modules/grouplist.cpp \
    widget/aboutdialog.cpp \
    widget/adddialog.cpp

HEADERS    += SimplePlayer.h \
    customvolumeslider.h \
    system.h \
    customseekslider.h \
    fulldialog.h \
    listdialog.h \
    modules/channel.h \
    modules/channelgroup.h \
    modules/grouplist.h \
    widget/aboutdialog.h \
    widget/adddialog.h

FORMS      += SimplePlayer.ui \
    fulldialog.ui \
    listdialog.ui \
    widget/aboutdialog.ui \
    widget/adddialog.ui

#LIBS       += -lVLCQtCore -lVLCQtWidgets


# Edit below for custom library location
LIBS       += -L/usr/local/lib -lVLCQtCore -lVLCQtWidgets
INCLUDEPATH += /usr/local/include

RESOURCES += \
    image.qrc
