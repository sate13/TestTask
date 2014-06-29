#include "threshholdingimageprovider.h"

ThreshholdingImageProvider::ThreshholdingImageProvider()
    : QQuickImageProvider(QQuickImageProvider::Pixmap) {}

QPixmap ThreshholdingImageProvider::requestPixmap(const QString& id, QSize *size, const QSize& requestedSize) {
    QImage _outputImage = INPUT_IMAGE;
    int _threshhold = id.toInt();

    for (int _w = 0; _w < INPUT_IMAGE.width(); _w++) {
        for (int _h = 0; _h < INPUT_IMAGE.height(); _h++) {
            /* Berechnen des Grauwertes des Pixels */
            int gray = qGray(INPUT_IMAGE.pixel(_w, _h));
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

    QPixmap _pixmap = QPixmap::fromImage(_outputImage);
    return _pixmap;
}

void ThreshholdingImageProvider::setInputImage(QImage inputImage) {
    this->INPUT_IMAGE = inputImage;
}
