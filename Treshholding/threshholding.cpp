#include "threshholding.h"

ThreshHolding::ThreshHolding(QImage* image)
    : image(image) { }

QImage ThreshHolding::changeThreshhold(const int& _a) {
    QImage _outputImage = *image;
    actualThreshhold = _a;

    for (int _w = 0; _w < image->width(); _w++) {
        for (int _h = 0; _h < image->height(); _h++) {
            int gray = qGray(image->pixel(_w, _h));
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
