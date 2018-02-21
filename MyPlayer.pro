QT    += core\
         gui\
        multimedia\
        multimediawidgets\
        widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyPlayer
TEMPLATE = app


DEFINES += QT_DEPRECATED_WARNINGS

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000
SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
