//
// Created by sc17h2z on 24/11/19.
//

#ifndef CW2_ONE_H
#define CW2_ONE_H

#include <QWidget>
#include <qmessagebox.h>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QTimer>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDir>
#include <QTimer>
class Two;
class Three;
class One : public QWidget
{
Q_OBJECT

public:
    explicit One(QWidget *parent = 0);

    QLabel *welcomeLabel;
    QPushButton *nextPushButton;
    QPushButton *childrenButton;
    QHBoxLayout *horizontalLayout;
    QLabel *usernameLabel;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *passwordLabel;
    QLineEdit *lineEdit_2;
    QTimer *time;

signals:
    void display(int number);

public slots:
    void on_nextPushButton_clicked();
    void on_childrenButton_clicked();

};


#endif //CW2_ONE_H
