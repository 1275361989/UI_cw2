/*
GROUP
   _____   ______
        | |
   _____| |______
  |              |
  |______________|


 FOR BEAUTY IS NOTHING BUT THE BEGINNING OF TERROR
     WHICH WE ARE BARELY ABLE TO ENDURE
          AND IT AMAZES US SO, BECAUSE IT SERENELY DISDAINS TO DISTROY US


                                                ----RAINER MARIA RILKE


 */

#include <QApplication>
#include "sysWindow.h"

using namespace std;


int main(int argc, char *argv[]) {

    // create the Qt Application
    QApplication app(argc, argv);

    //I think it's time we blow this scene
    // get everybody and stuff together


    // create the main window
    sysWindow *window=new sysWindow();

    //adjust the window
    window->setMinimumSize(300,580);

    //Ok! 3,2,1, Let's jam!
    window->show();


    //The dream is over  --John Lennon<God>
    return app.exec();
}



