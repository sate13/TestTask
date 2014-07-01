#ifndef THRESHHOLDINGIMAGEPROVIDER_H
#define THRESHHOLDINGIMAGEPROVIDER_H

#include <QObject>
#include <QQuickImageProvider>
#include <QString>
#include <QImage>
#include <QPixmap>

class ThreshholdingImageProvider : public QQuickImageProvider, public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString source READ source WRITE setSource NOTIFY sourceChanged)

public:
    ThreshholdingImageProvider();

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);
    QString source();

public slots:
    void setSource(const QString& url);

signals:
    void sourceChanged();

private:
    QString inputImageUrl;
};

#endif // THRESHHOLDINGIMAGEPROVIDER_H
