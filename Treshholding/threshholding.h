#ifndef THRESHHOLDING_H
#define THRESHHOLDING_H

#include <QImage>

class ThreshHolding
{
    const QImage originalImage;
    QImage outputImage;
    int actualThreshhold;

public:
    ThreshHolding(QString _imageSource) {}
    QImage changeThreshhold(const int _a);

private:
    int generateThreshholding();
};

#endif // THRESHHOLDING_H
