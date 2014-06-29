#include <QApplication>
#include <QQmlApplicationEngine>

#include <QtQml>

#include <Treshholding/threshholding.h>
#include <Treshholding/threshholdingimageprovider.h>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<ThreshHolding>("com.testTask.threshholding", 1, 0, "Threshholding");
    engine.addImageProvider("threshholdingImage", new ThreshholdingImageProvider);
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
