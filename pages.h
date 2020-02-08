//
// Created by sc17h2z on 24/11/19.
//

#ifndef CW2_PAGES_H
#define CW2_PAGES_H

#include <QWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <string>
#include "the_player.h"
#include "the_button.h"
class One;
class Two;
class Three;
class QStackedLayout;
class QVBoxLayout;

class Pages : public QWidget{
Q_OBJECT

public:
    Pages();
    vector<TheButtonInfo> getInfoIn (string loc);

private:
    One *one;
    Two *two;
    Three *three;
    QStackedLayout *stackLayout;
    QVBoxLayout *mainLayout;

};


#endif //CW2_PAGES_H
