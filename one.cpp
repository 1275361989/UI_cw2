//
// Created by sc17h2z on 24/11/19.
//

#include "one.h"

One::One(QWidget *parent) :QWidget(parent){

    // set palette
    QPalette printBackground;
    //set brush, add the picture and adjust the scale
    printBackground.setBrush(QPalette::Background,QBrush(QPixmap("/home/csunix/sc17h2z/CLionProjects/cw2 (2rd)/background/-32cc776aede8ca0e.jpg").scaled(this->size())));
    //set the palette
    setPalette(printBackground);
    //fill the background
    setAutoFillBackground(true);


    //set fond and size
    QFont font;
    font.setPointSize(30);
    // the label to show the welcome
    welcomeLabel = new QLabel();
    welcomeLabel->setObjectName(QString::fromUtf8("label"));
    welcomeLabel->setText("Welcome");
    welcomeLabel->setFont(font);


    // create the horizontal layout to show welcome label
    horizontalLayout_3=new QHBoxLayout();
    horizontalLayout_3->addStretch();
    horizontalLayout_3->addWidget(welcomeLabel);
    horizontalLayout_3->addStretch();


    //set username input
    QFont font1;
    font1.setPointSize(20);

    usernameLabel = new QLabel();
    usernameLabel->setText("Username");
    usernameLabel->setFont(font1);

    //input the username
    lineEdit = new QLineEdit();

    //add the usename label and input line together
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->addStretch();
    horizontalLayout->addWidget(usernameLabel);
    horizontalLayout->addWidget(lineEdit);
    horizontalLayout->addStretch();


    //set password input
    //password label
    passwordLabel = new QLabel();
    passwordLabel->setText("Password:");
    passwordLabel->setFont(font1);

    //password input
    lineEdit_2 = new QLineEdit();
    lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

    //add the password label and input line together
    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->addStretch();
    horizontalLayout_2->addWidget(passwordLabel);
    horizontalLayout_2->addWidget(lineEdit_2);
    horizontalLayout_2->addStretch();

    //login button
    nextPushButton = new QPushButton();
    //set object name, so the slots can be connected by its name
    nextPushButton->setObjectName(QString::fromUtf8("nextPushButton"));
    //set style text, and status tip
    nextPushButton->setText("login");
    nextPushButton->setStyleSheet("font-size: 20px;text-decoration: none;color:black ;padding: 3px 5px;border:1px solid #555555;border-radius:5px;");
    nextPushButton->setStatusTip("Enter");

    //children enter button
    childrenButton = new QPushButton();
    childrenButton->setObjectName(QString::fromUtf8("childrenButton"));
    //set style text, and status tip
    childrenButton->setText("Children");
    childrenButton->setStatusTip("Let's jam!");
    childrenButton->setStyleSheet("font-size: 20px;background-color: #008CBA;text-decoration: none;color:black ;padding: 3px 5px;border:1px solid #555555;border-radius:5px;");

    //add the login button and children mode button together
    horizontalLayout_1 = new QHBoxLayout();
    horizontalLayout_1->addStretch();
    horizontalLayout_1->addWidget(nextPushButton);
    horizontalLayout_1->addWidget(childrenButton);
    horizontalLayout_1->addStretch();

    //top layout to set all
    QGridLayout *top = new QGridLayout();

    top->addLayout(horizontalLayout_3,0,0,1,2);
    top->addLayout(horizontalLayout,1,0,1,2);
    top->addLayout(horizontalLayout_2,2,0,1,2);
    top->addLayout(horizontalLayout_1,3,1,1,1);
    //set all
    setLayout(top);

    //create a timer, if the user login successful or click children mode, it will start
    time=new QTimer();

    // the nextpushbutton and children button will connect the slot by this
    QMetaObject::connectSlotsByName(this);

}
void One::on_nextPushButton_clicked()
{
    // a fake login
    // username 25
    // password 25
    if (this->lineEdit->text()=="25"&&this->lineEdit_2->text()=="25")
    {
        emit display(1);
        //the timer start
        time->start(1500);
    }
    //or warning
    else
        QMessageBox::information(NULL,tr("warning"),tr("username or password error"));
}
void One::on_childrenButton_clicked()
{

    emit display(1);
    time->start(1500);
}

