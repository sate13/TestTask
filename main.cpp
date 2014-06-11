#include <QApplication>
#include <QQmlApplicationEngine>

#include "MainWindow/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("Probeaufgabe des CellTracker");

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
