/**
* @file threshholding.cpp
* @author Marc Satkowski
* @date 13/06/2014
* @version 1.0
*/

#include "threshholding.h"

ThreshHolding::ThreshHolding(QImage* image)
    : image(image) { }

QImage ThreshHolding::changeThreshhold(const int& _a) {
    /* Erstellen des neuen Outputbildes und Ändern des Schwellenwertes */
    QImage _outputImage = *image;
    actualThreshhold = _a;

    /* Schleifen zum Iterieren über alle Pixel des Bildes */
    for (int _w = 0; _w < image->width(); _w++) {
        for (int _h = 0; _h < image->height(); _h++) {
            /* Berechnen des Grauwertes des Pixels */
            int gray = qGray(image->pixel(_w, _h));
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
