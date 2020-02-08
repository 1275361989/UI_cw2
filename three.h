//
// Created by sc17h2z on 25/11/19.
//

#ifndef CW2_THREE_H
#define CW2_THREE_H
#include <iostream>

#include <QWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QImageReader>
#include <QMediaPlaylist>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDir>
#include <QTimer>
#include <QStatusBar>
#include <QDir>
#include <QtCore/QDir>
#include "the_player.h"
#include <QtCore/QDirIterator>
#include <QtWidgets/QSlider>
#include "mySlider.h"

class One;
class Three : public QWidget
{
Q_OBJECT

public:
    QLabel *navLabel;
    QPushButton *previousPushButton;
    QPushButton *stopButton;
    QLabel *voice;
    explicit Three(QWidget *parent = 0);
    vector<TheButtonInfo> getInfoIn (string loc);

    vector<TheButtonInfo> *videos;
    QVideoWidget *videoWidget;
    ThePlayer *player;
    QTimer *timer;
    mySlider *videoBar;
    QSlider *voiceBar;
signals:
    void display(int number);
    void clicked();

public slots:
    void on_previousPushButton_clicked();
    void onTimeout();
    void voiceChange();
    void videoBar_clicked();
    void videoBar_moved();
    void videoBar_released();


};




#endif //CW2_THREE_H
