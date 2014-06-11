#include "threshholding.h"

ThreshHolding::ThreshHolding(QString _imageSource) {
    //Das OriginalImage wird festegelegt über den Source.
    originalImage = new QImage(_imageSource);
    generateThreshholding();
}

int ThreshHolding::generateThreshholding() {
    int _actualThreshhold = 0;
    return _actualThreshhold;
}

QImage ThreshHolding::changeThreshhold(const int _a) {
    // Altes OuptutImage wird aus dem Speicher gelöscht
    if(outputImage.isNull()) {
        outputImage.~QImage();
    }

    // Neues OutputImage wird erstellt. Selbe Größe und Format wie das OriginalImage.
    outputImage = *(new QImage(originalImage.size(), originalImage.format()));
    actualThreshhold = _a;
    return outputImage;
}
