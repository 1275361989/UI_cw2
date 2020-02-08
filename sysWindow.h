//
// Created by sc17h2z on 09/12/19.
//

#ifndef CW2_SYSWINDOW_H
#define CW2_SYSWINDOW_H
#include <QMainWindow>
#include <QHBoxLayout>
#include <QStatusBar>
#include "pages.h"
#include <QApplication>
class sysWindow : public QMainWindow {
public:
    sysWindow();

private:

    QWidget* _mainWidget;
    void createPages();
    void createMenu();
};


#endif //CW2_SYSWINDOW_H
