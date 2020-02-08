//
// Created by twak on 11/11/2019.
//

#include "the_player.h"
#include <iostream>
using namespace std;

// all buttons have been setup, store pointers here
void ThePlayer::setContent(std::vector<TheButton*>* b, std::vector<TheButtonInfo>* i){
    buttons = b;
    infos = i;
    jumpTo(buttons -> at(0) -> info);
}
void ThePlayer::playStateChanged (QMediaPlayer::State ms) {
    switch (ms) {
        case QMediaPlayer::State::StoppedState:
        {
            play(); // starting playing again...
        }

    }
}
void ThePlayer::playStateChanged2 () {
    //if the state is playing, pause
    if(this->state()==PlayingState) {
            this->pause();
        }
    //if the state is playing, pause
    else if(this->state()==PausedState){
            this->play();
        }
}

void ThePlayer::jumpTo (TheButtonInfo* button) {
    setMedia( * button -> url);
    play();
}
