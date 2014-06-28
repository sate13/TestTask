/**
* @file threshholding.h
* @author Marc Satkowski
* @date 13/06/2014
* @version 1.0
*/

#ifndef THRESHHOLDING_H
#define THRESHHOLDING_H

#include <QObject>
#include <QImage>
#include <QLabel>

class ThreshHolding : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QImage image READ image WRITE setImage NOTIFY imageChanged)
    Q_PROPERTY(int threshhold READ threshhold WRITE setThreshhold NOTIFY threshholdChanged)

public:
    ThreshHolding() = default;
    ThreshHolding(QImage* image);

    QImage image() const;
    void setImage(const QImage& image);
    int threshhold() const;
    void setThreshhold(const int& threshhold);

public slots:
    QImage changeThreshhold(QLabel& imageLabel, const int& _a);

signals:
    void imageChanged();
    void threshholdChanged();

private:
    void generateThreshholding();

    QImage* threshholdImage;
    int actualThreshhold;

};

#endif // THRESHHOLDING_H
