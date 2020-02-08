//
// Created by sc17h2z on 14/12/19.
//

#include "mySlider.h"
//override the mousepressEVent
//since the default mousepressevent just jump a certain distance
//this method is to jump to any location
void mySlider::mousePressEvent(QMouseEvent *ev) {

    QSlider::mousePressEvent(ev);
    // calculte the position
    double location=ev->pos().x()/(double)width();
    setValue(location*(maximum()-minimum())+minimum());
    emit mySliderClicked();
}
