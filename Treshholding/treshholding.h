#ifndef TRESHHOLDING_H
#define TRESHHOLDING_H

#include <QImage>

class TreshHolding
{
public:
    TreshHolding(QImage _image)
        :image(_image) {}
    bool generateThreshholding();
    QImage changeThreshhold(const int* _a);
private:
    const QImage image;
};

#endif // TRESHHOLDING_H
