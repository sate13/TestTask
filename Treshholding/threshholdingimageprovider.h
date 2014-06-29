#ifndef THRESHHOLDINGIMAGEPROVIDER_H
#define THRESHHOLDINGIMAGEPROVIDER_H

#include <QQuickImageProvider>
#include <QImage>
#include <QPixmap>

class ThreshholdingImageProvider : public QQuickImageProvider
{
public:
    ThreshholdingImageProvider();

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);

    void setInputImage(QImage inputImage);

private:
    QImage INPUT_IMAGE;
};

#endif // THRESHHOLDINGIMAGEPROVIDER_H
