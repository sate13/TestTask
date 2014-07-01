#include "threshholdingimageprovider.h"

ThreshholdingImageProvider::ThreshholdingImageProvider()
    : QQuickImageProvider(QQuickImageProvider::Pixmap) {}

QString ThreshholdingImageProvider::source() {
    return this->inputImageUrl;
}

void ThreshholdingImageProvider::setSource(const QString &url) {
    if(this->inputImageUrl == url) { return; }

    this->inputImageUrl = url;
    emit sourceChanged();
}

QPixmap ThreshholdingImageProvider::requestPixmap(const QString& id, QSize *size, const QSize& requestedSize) {
    QImage _outputImage = QImage(inputImageUrl);
    int _threshhold = id.toInt();

    for (int _w = 0; _w < _outputImage.width(); _w++) {
        for (int _h = 0; _h < _outputImage.height(); _h++) {
            /* Berechnen des Grauwertes des Pixels */
            int gray = qGray(_outputImage.pixel(_w, _h));
            /* Abgleich des Grauwertes mit dem Schwellen wert:
             * wenn darunter -> pixel wird weiß
             * wenn darüber -> Pixel wird schwarz */
            if(gray < _threshhold) {
                _outputImage.setPixel(_w, _h, qRgb(0, 0, 0));
            }
            else {
                _outputImage.setPixel(_w, _h, qRgb(255, 255, 255));
            }
        }
    }

    return QPixmap::fromImage(_outputImage);
}
