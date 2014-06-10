#ifndef TRESHHOLDING_H
#define TRESHHOLDING_H

#include <QImage>

class ThreshHolding
{
    const QImage image;
public:
    ThreshHolding(QImage _image)
        :image(_image) {}
    bool generateThreshholding();
    QImage changeThreshhold(const int* _a);
};

#endif // TRESHHOLDING_H
