#-------------------------------------------------
#
# Project created by QtCreator 2019-03-05T00:32:24
#
#-------------------------------------------------

QT       += core gui widgets datavisualization

CONFIG += c++17
LIBS += -pthread

TARGET = Polak_Ribiere
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        sources/MainWindow.cpp \
        sources/Graph.cpp \
        sources/FunctionInput.cpp

HEADERS += \
        include/MainWindow.h \
        include/Graph.h \
        include/FunctionInput.h

FORMS += \
        forms/mainwindow._ui \
        forms/graph._ui \
        forms/functioninput._ui

MOC_DIR = forms

RESOURCES += \
        images.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
