//
// Created by sc17h2z on 24/11/19.
//

#include "pages.h"
#include "one.h"
#include "two.h"
#include "three.h"
#include <QStackedLayout>

//stacklayout is used to create multiple pages
Pages::Pages():QWidget()
{
    //create corresponding pages
    one = new One;
    two = new Two;
    three = new Three;

    //add them in stacklayout
    stackLayout = new QStackedLayout;
    stackLayout->addWidget(one);
    stackLayout->addWidget(two);
    stackLayout->addWidget(three);

    //set page index
    connect(one, &One::display, stackLayout, &QStackedLayout::setCurrentIndex);             // 0
    connect(two, &Two::display, stackLayout, &QStackedLayout::setCurrentIndex);             // 1
    connect(three, &Three::display, stackLayout, &QStackedLayout::setCurrentIndex);

    //if user logins or clicks children mode in first page, the second pages will play the pictures
    connect(one->time,SIGNAL(timeout()),two,SLOT(showOnePic()));

    //if user clicks buttons(9) in second picture , the third pages will play the correspomding video
    for ( int i = 0; i < 9; i++ ) {
        two->buttons->at(i)->connect(two->buttons->at(i), SIGNAL(jumpTo(TheButtonInfo * )), three->player,
                                     SLOT (jumpTo(TheButtonInfo * )));
        two->buttons->at(i)->init(&(three->videos)->at(i));
        three->player->setContent(two->buttons, three->videos);
    }

    //create main layout
    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(stackLayout);

    setLayout(mainLayout);


}

