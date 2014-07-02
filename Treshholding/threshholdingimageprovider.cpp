/**
* @file threshholdingimageprovider.h
* @author Marc Satkowski
* @date 02/07/2014
* @version 1.0
*/

#include "threshholdingimageprovider.h"

ThreshholdingImageProvider::ThreshholdingImageProvider()
    : QQuickImageProvider(QQuickImageProvider::Pixmap) {}

QPixmap ThreshholdingImageProvider::requestPixmap(const QString& id, QSize *size, const QSize& requestedSize) {
    /* Auswerten der id und Aufteilung in Schwellenwert und source */
    QString _newId = id;
    _newId.replace(0, 8, "/");
    /* Ersetzen des "file:///" durch "/" */
    QStringList _list = _newId.split(":*:");
    QImage _outputImage = QImage(_list.first());
    int _threshhold = _list.last().toInt();

    /* Schleifen zum Iterieren über alle Pixel des Bildes. */
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

    /* Zurückgeben der Pixmap des Bildes. */
    return QPixmap::fromImage(_outputImage);
}
