/**
* @file main.cpp
* @author Marc Satkowski
* @date 02/07/2014
* @version 1.0
*/

#include <QApplication>
#include <QQmlApplicationEngine>

#include <QtQml>

#include <Treshholding/threshholdingimageprovider.h>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;

    engine.addImageProvider("threshholdingImage", new ThreshholdingImageProvider);
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
