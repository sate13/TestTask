/**
* @file textarea.h
* @author Marc Satkowski
* @date 16/06/2014
* @version 1.0
*/

#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <QLineEdit>
#include <QString>

class TextArea : public QLineEdit
{
    Q_OBJECT

public slots:
    void setNum(int number);
};

#endif // TEXTAREA_H
