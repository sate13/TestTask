/**
* @file threshholding.cpp
* @author Marc Satkowski
* @date 13/06/2014
* @version 1.0
*/

#include "threshholding.h"


QImage ThreshHolding::image() const {
    return *threshholdImage;
}
void ThreshHolding::setImage(const QImage& image) {
    *threshholdImage = image;
    emit imageChanged();
}
int ThreshHolding::threshhold() const {
    return actualThreshhold;
}
void ThreshHolding::setThreshhold(const int &threshhold) {
    actualThreshhold = threshhold;
    emit threshholdChanged();
}

ThreshHolding::ThreshHolding(QImage* image)
    : threshholdImage(image) { }

QImage ThreshHolding::changeThreshhold(QLabel& imageLabel, const int& _a) {
    /* Erstellen des neuen Outputbildes und Ändern des Schwellenwertes */
    QImage _outputImage = *threshholdImage;
    actualThreshhold = _a;

    /* Schleifen zum Iterieren über alle Pixel des Bildes */
    for (int _w = 0; _w < threshholdImage->width(); _w++) {
        for (int _h = 0; _h < threshholdImage->height(); _h++) {
            /* Berechnen des Grauwertes des Pixels */
            int gray = qGray(threshholdImage->pixel(_w, _h));
            /* Abgleich des Grauwertes mit dem Schwellen wert:
             * wenn darunter -> pixel wird weiß
             * wenn darüber -> Pixel wird schwarz */
            if(gray < actualThreshhold) {
                _outputImage.setPixel(_w, _h, qRgb(0, 0, 0));
            }
            else {
                _outputImage.setPixel(_w, _h, qRgb(255, 255, 255));
            }
        }
    }

    return _outputImage;
}
