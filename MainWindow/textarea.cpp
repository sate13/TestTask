/**
* @file textarea.cpp
* @author Marc Satkowski
* @date 16/06/2014
* @version 1.0
*/

#include "textarea.h"

void TextArea::setNum(int number) {
    QString _string = QString::number(number);
    setText(_string);
    emit textChanged(_string);
}
