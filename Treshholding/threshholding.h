#ifndef THRESHHOLDING_H
#define THRESHHOLDING_H

#include <QImage>
#include <QLabel>

class ThreshHolding
{
public:
    ThreshHolding(QImage image);
    QImage changeThreshhold(const QLabel& imageLabel, const int& _a);

private:
    int generateThreshholding();    

    QImage originalImage;
    QImage outputImage;
    int actualThreshhold;

};

#endif // THRESHHOLDING_H
