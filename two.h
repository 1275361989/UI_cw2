//
// Created by sc17h2z on 24/11/19.
//
#include <QWidget>
#ifndef CW2_TWO_H
#define CW2_TWO_H
#include <iostream>

#include <QtMultimediaWidgets/QVideoWidget>
#include <QMediaPlaylist>
#include <string>
#include <QtWidgets/QHBoxLayout>
#include <QtCore/QFileInfo>
#include <QtWidgets/QFileIconProvider>
#include <QImageReader>
#include <QtCore/QDir>
#include <QtCore/QDirIterator>
#include <QtWidgets/QLabel>
#include "the_player.h"
#include "the_button.h"
#include <QFileInfo>
#include <QFileInfoList>
#include <QDir>
#include <QtWidgets/QScrollArea>
class Two : public QWidget
{
    Q_OBJECT

public:
    QLabel *navLabel;
    QPushButton *previousPushButton;
    explicit Two(QWidget *parent = 0);
    QLabel *pictures;
    TheButton *button;
    vector<TheButton*>* buttons;
    void setScrollarea(QWidget *Widget);
private:
    int i;
    int num;
signals:
    void display(int number);
public slots:
    void showOnePic();


private slots:
    void on_previousPushButton_clicked();
    void on_button0_clicked();
    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_button4_clicked();
    void on_button5_clicked();
    void on_button6_clicked();
    void on_button7_clicked();
    void on_button8_clicked();


private:

    QString path;
    QFileInfo fileinfo;
    QFileInfoList GetFileList(QString path);


};

#endif //CW2_TWO_H
