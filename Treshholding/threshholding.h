#ifndef THRESHHOLDING_H
#define THRESHHOLDING_H

#include <QImage>
#include <QLabel>

class ThreshHolding
{

public:
    ThreshHolding() = default;
    ThreshHolding(QImage* image);
    QImage changeThreshhold(const int& _a);

private:
    void generateThreshholding();

    QImage* image;
    int actualThreshhold;

};

#endif // THRESHHOLDING_H
