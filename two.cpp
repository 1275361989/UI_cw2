//
// Created by sc17h2z on 24/11/19.
//

#include "two.h"

Two::Two(QWidget *parent) : QWidget(parent){
// collect all the videos in the folder

    // a row of buttons
    QWidget *buttonWidget = new QWidget();
    // a list of the buttons
    buttons = new vector<TheButton*>();

    //create the navlabel
    QFont font;
    font.setPointSize(20);
    navLabel = new QLabel();
    navLabel->setText("nav");
    navLabel->setFont(font);


    //back button
    previousPushButton = new QPushButton();
    previousPushButton->setObjectName(QString::fromUtf8("previousPushButton"));
    //set text style and statustip
    previousPushButton->setText("back");
    previousPushButton->setStatusTip("back");
    previousPushButton->setStyleSheet("font-size: 20px;text-decoration: none;color:black ;padding: 3px 5px;border:1px solid #555555;border-radius:5px;");


    //set the carousel picture
    pictures = new QLabel();
    pictures->setScaledContents(true);

    // the buttons are arranged by grid
    QGridLayout* layout = new QGridLayout();
    layout->addWidget(navLabel,0,2,1,1);
    layout->addWidget(pictures,2,0,4,3);

    //set scrroll bar
    setScrollarea(buttonWidget);
    layout->addWidget(buttonWidget,9,0,9,3);
    layout->addWidget(previousPushButton,0,0,1,1);

    //set the grid layout
    setLayout(layout);

    //read picture which is used to carousel
    path = "/home/csunix/sc17h2z/CLionProjects/video/picture";
    //number of pictures
    num = GetFileList(path).size();
    i=0;

    QMetaObject::connectSlotsByName(this);
}
void Two::setScrollarea(QWidget *Widget){
    //add a new layout to store widget
    QLayout *scrollLayout= new QGridLayout(Widget);
    //create a scrollare which contains wigdet
    QScrollArea *scrollArea=new QScrollArea(Widget);
    //create content
    QWidget *content=new QWidget();
    //resize
    scrollArea->setWidgetResizable(true);
   //set a layout for content
    QGridLayout *contentLayout= new QGridLayout();
    content->setLayout(contentLayout);

    for ( int i = 0; i < 9; i++ ) {
        button = new TheButton(content);
        //for each button, give them a object name
        if(i==0)
            button->setObjectName(QString::fromUtf8("button0"));
        else if(i==1)
            button->setObjectName(QString::fromUtf8("button1"));
        else if(i==2)
            button->setObjectName(QString::fromUtf8("button2"));
        else if(i==3)
            button->setObjectName(QString::fromUtf8("button3"));
        else if(i==4)
            button->setObjectName(QString::fromUtf8("button4"));
        else if(i==5)
            button->setObjectName(QString::fromUtf8("button5"));
        else if(i==6)
            button->setObjectName(QString::fromUtf8("button6"));
        else if(i==7)
            button->setObjectName(QString::fromUtf8("button7"));
        else if(i==8)
            button->setObjectName(QString::fromUtf8("button8"));

        // set category label
        QLabel *category0=new QLabel;
        category0->setText("Popular");
        QLabel *category1=new QLabel;
        category1->setText("New released");
        QLabel *category2=new QLabel;
        category2->setText("Animated");

        //set grid layout
        contentLayout->addWidget(category0,0,0,1,1);
        contentLayout->addWidget(category1,2,0,1,1);
        contentLayout->addWidget(category2,4,0,1,1);
        if(i<3)
            contentLayout->addWidget(button,1,i,1,1);
        else if(i<6)
            contentLayout->addWidget(button,3,i-3,1,1);
        else
            contentLayout->addWidget(button,5,i-6,1,1);

        //set status tip
        button->setStatusTip("click here!!");
        buttons->push_back(button);
    }

    //add the content in scrollarea
    scrollArea->setWidget(content);
    //add scrollarea to layout
    scrollLayout->addWidget(scrollArea);
}

void Two::on_previousPushButton_clicked()
{
    //if previous button clicked , back to page index 0
    emit display(0);
}
//if these buttons clicked , go to page index 2
void Two::on_button0_clicked()
{
    emit display(2);
}
void Two::on_button1_clicked()
{
    emit display(2);
}
void Two::on_button2_clicked()
{
    emit display(2);
}
void Two::on_button3_clicked()
{
    emit display(2);
}
void Two::on_button4_clicked()
{
    emit display(2);
}
void Two::on_button5_clicked()
{
    emit display(2);
}
void Two::on_button6_clicked()
{
    emit display(2);
}
void Two::on_button7_clicked()
{
    emit display(2);
}
void Two::on_button8_clicked()
{
    emit display(2);
}



void Two::showOnePic()
{
    QImage image;
    //get file
    fileinfo = GetFileList(path).at(i);
    image.load(fileinfo.filePath());
    //qDebug()<<"fail!";
    //set pic
    pictures->setPixmap(QPixmap::fromImage(image));
    i++;
    if(i == num)
        i=0;
}


QFileInfoList Two::GetFileList(QString path)
{
    QDir dir(path);
    //get file list
    QFileInfoList file_list = dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    QFileInfoList folder_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    //read the fold
    for(int i = 0; i != folder_list.size(); i++)
    {
        QString name = folder_list.at(i).absoluteFilePath();
        //get a children file list
        QFileInfoList child_file_list = GetFileList(name);
        //append
        file_list.append(child_file_list);
    }

    return file_list;
}