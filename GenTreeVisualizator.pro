#-------------------------------------------------
#
# Project created by QtCreator 2014-09-06T21:26:47
#
#-------------------------------------------------

QT       += core gui
CONFIG   += console c++11
unix: LIBS += -lcppunit
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GenTreeVisualizator
TEMPLATE = app


SOURCES += main.cpp\
        Visualizator/Visualizator.cpp \
    Nodes/Element.cpp \
    Nodes/ElementList.cpp \
    Visualizator/ElementWidget.cpp

HEADERS  += Visualizator/Visualizator.hpp \
    Nodes/Element.hpp \
    Nodes/ElementList.hpp \
    Tests/Nodes/TestElement.hpp \
    Tests/Nodes/TestElementList.hpp \
    Visualizator/ElementWidget.hpp

FORMS    += Visualizator/Visualizator.ui \
    Visualizator/ElementWidget.ui

RESOURCES += \
    Visualizator/Resources.qrc
