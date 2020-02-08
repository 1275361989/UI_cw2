//
// Created by sc17h2z on 25/11/19.
//

#include <QtWidgets/QHBoxLayout>

#include "three.h"

vector<TheButtonInfo> Three::getInfoIn (string loc) {

    vector<TheButtonInfo> out =  vector<TheButtonInfo>();
    QDir dir(QString::fromStdString(loc) );

    QDirIterator it(dir);
    while (it.hasNext()) { // for all files

        QString f = it.next();

        if (!f.contains(".png")&&((f.contains(".MOV"))||f.contains(".mp4"))) { // add the filter
            QString thumb = f.left( f .length() - 4) +".png";
            if (QFile(thumb).exists()) { // but a png thumbnail exists
                QImageReader *imageReader = new QImageReader(thumb);
                QImage sprite = imageReader->read(); // read the thumbnail
                if (!sprite.isNull()) {
                    QIcon* ico = new QIcon(QPixmap::fromImage(sprite)); // voodoo to create an icon for the button
                    QUrl* url = new QUrl(QUrl::fromLocalFile( f )); // convert the file location to a generic url
                    out . push_back(TheButtonInfo( url , ico  ) ); // add to the output list
                }
                else
                    cerr << "warning: skipping video because I couldn't process thumbnail " << thumb.toStdString() << endl;
            }
            else
                cerr << "warning: skipping video because I couldn't find thumbnail " << thumb.toStdString() << endl;
        }
    }
    return out;
}

Three::Three(QWidget *parent):QWidget(parent){

    QFont font;
    font.setPointSize(20);

    //create the navlabel
    navLabel = new QLabel();
    navLabel->setFont(font);
    navLabel->setText("nav");

    //back button
    previousPushButton = new QPushButton();
    previousPushButton->setObjectName(QString::fromUtf8("previousPushButton"));
    //set text style and statustip
    previousPushButton->setText("back");
    previousPushButton->setStatusTip("back to index page");
    previousPushButton->setStyleSheet("font-size: 20px;text-decoration: none;color:black ;padding: 3px 5px;border:1px solid #555555;border-radius:5px;");

    // read videos  and in pages.cpp, connect the videos and button
    videos= new vector<TheButtonInfo> ;
    *videos = getInfoIn(  "/home/csunix/sc17h2z/CLionProjects/video/ani");

    //set video wiget and player
    videoWidget = new QVideoWidget;
    player = new ThePlayer;
    player->setVideoOutput(videoWidget);
    videoWidget->setStatusTip("watch here!");


    //set the button layout
    QHBoxLayout *buttonLayout=new QHBoxLayout();

    //set stop button
    stopButton=new QPushButton();
    stopButton->setText("stop/continue");
    stopButton->setObjectName(QString::fromUtf8("stopButton"));
    stopButton->setStatusTip("stop/continue");
    stopButton->setStyleSheet("font-size: 20px;text-decoration: none;color:black ;padding: 3px 5px;border:1px solid #555555;border-radius:5px;");

    //set voice label
    voice=new QLabel;
    voice->setText("Volume");
    voice->setStatusTip("adjust voice");

    // set the video bar
    videoBar=new mySlider();
    //set orientation
    videoBar->setOrientation(Qt::Horizontal);
    //set range
    videoBar->setMaximum(1000);
    videoBar->setMinimum(0);

    videoBar->setStatusTip("drag now!!!");

    // set the volume bar
    voiceBar=new QSlider;
    //set orientation
    voiceBar->setOrientation(Qt::Vertical);
    //set range
    voiceBar->setRange(0,10);
    voiceBar->setMaximumHeight(50);

    //set timer to trace the progress of video
    timer=new QTimer;
    timer->setInterval(1000);
    timer->start();

    //set layout of all buttons
    buttonLayout->addStretch();
    buttonLayout->addWidget(stopButton);
    buttonLayout->addStretch();
    buttonLayout->addWidget(voice);
    buttonLayout->addWidget(voiceBar);
    buttonLayout->addStretch();

    //interval
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimeout()));

    //release that user can drag the progrss bar
    //connect the myslider
    connect(videoBar,&mySlider::mySliderClicked,this,&Three::videoBar_clicked);
    connect(videoBar,&mySlider::sliderMoved,this,&Three::videoBar_moved);
    connect(videoBar,&mySlider::sliderReleased,this,&Three::videoBar_released);

    //if voice bar moved, change the volume
    connect(voiceBar,&QSlider::sliderMoved,this,&Three::voiceChange);
    //if stop button clicked, stop/continue
    connect (stopButton, SIGNAL (clicked()), player, SLOT ( playStateChanged2()));


    //the top layout
    QGridLayout *layout1=new QGridLayout;
    layout1->addWidget(navLabel,0,2,1,1);
    layout1->addWidget(previousPushButton,0,0,1,1);
    layout1->addWidget(videoWidget,1,0,7,3);
    layout1->addLayout(buttonLayout,8,0,1,3);
    layout1->addWidget(videoBar,9,0,1,3);

    setLayout(layout1);

    QMetaObject::connectSlotsByName(this);

}


void Three::on_previousPushButton_clicked()
{
    emit display(1);
}
void Three::onTimeout() {
    //calculate the progress
    //1000 is interval
    videoBar->setValue(player->position()*1000/player->duration());
}
void Three::voiceChange() {
    //reset the volume
    player->setVolume(voiceBar->value());
}
void Three::videoBar_clicked(){
    player->setPosition(videoBar->value()*player->duration()/1000);
}
void Three::videoBar_moved(){
    //when the videobar is moved, stop the timer
    timer->stop();
    player->setPosition(videoBar->value()*player->duration()/1000);
}
void Three::videoBar_released(){
    //when released, start the timer
    timer->start();
}