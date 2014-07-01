#include <QApplication>
#include <QQmlApplicationEngine>

#include <QtQml>

#include <Treshholding/threshholding.h>
#include <Treshholding/threshholdingimageprovider.h>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<ThreshholdingImageProvider>("com.testTask.threshholding", 1, 0, "ImageProvider");
    engine.addImageProvider("threshholdingImage", new ThreshholdingImageProvider);
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
