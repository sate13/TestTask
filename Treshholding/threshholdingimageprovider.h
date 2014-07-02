/**
* @file threshholdingimageprovider.cpp
* @author Marc Satkowski
* @date 02/07/2014
* @version 1.0
*/

#ifndef THRESHHOLDINGIMAGEPROVIDER_H
#define THRESHHOLDINGIMAGEPROVIDER_H

#include <QObject>
#include <QQuickImageProvider>
#include <QString>
#include <QImage>
#include <QPixmap>

class ThreshholdingImageProvider : public QQuickImageProvider
{
public:
    ThreshholdingImageProvider();

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);

private:
    QString inputImageUrl;
};

#endif // THRESHHOLDINGIMAGEPROVIDER_H
