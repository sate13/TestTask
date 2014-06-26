TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    Treshholding/threshholding.cpp \
    MainWindow/mainwindow.cpp \
    MainWindow/textarea.cpp

RESOURCES += \
    qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Treshholding/threshholding.h \
    MainWindow/mainwindow.h \
    MainWindow/textarea.h

CXXFLAGS += -std=c++11
