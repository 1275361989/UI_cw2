//
// Created by sc17h2z on 13/12/19.
//

#ifndef CW2_MYSLIDER_H
#define CW2_MYSLIDER_H

#include <QSlider>
#include <QMouseEvent>
#include <QCoreApplication>

class mySlider :public QSlider{
    Q_OBJECT
public:
    mySlider(QWidget *parent=0):QSlider(parent)
    {

    }

protected:
    void mousePressEvent(QMouseEvent *ev);
signals:
    void mySliderClicked();


};


#endif //CW2_MYSLIDER_H
