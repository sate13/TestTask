#include "threshholding.h"

ThreshHolding::ThreshHolding(QImage* image)
    : image(image) { }

QImage ThreshHolding::changeThreshhold(const int& _a) {
    // Neues OutputImage wird erstellt. Selbe Größe und Format wie das OriginalImage.
    QImage _outputImage = image->alphaChannel();
    actualThreshhold = _a;

    return _outputImage;
}
