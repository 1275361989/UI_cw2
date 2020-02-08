//
// Created by sc17h2z on 09/12/19.
//

#include "sysWindow.h"
sysWindow::sysWindow() {
    //add pages
    createPages();

    //add mune and status bar
    createMenu();
}

void sysWindow::createPages() {

    QHBoxLayout* layout=new QHBoxLayout();

    //create multiple pages
    Pages *pages=new Pages();

    layout->addWidget(pages);

    //create the main widget
    _mainWidget = new QWidget();
    _mainWidget->setLayout(layout);

    //set main widget
    setCentralWidget(_mainWidget);

}
void sysWindow::createMenu() {
    // statusbar itself show message
    statusBar()->showMessage("It is the status bar");

    // create menu
    QMenu* fileMenu = menuBar()->addMenu("&Exit");

    //create quit and add action
    QAction* quit = fileMenu->addAction("Quit");
    quit->setShortcuts(QKeySequence::Quit);
    quit->setStatusTip("Quit");

    //connect the quit and application
    connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
}
