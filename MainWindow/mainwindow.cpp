#include "mainwindow.h"

MainWindow::MainWindow()
{
    createAcions();
    createMenu();
//    createImageField();
//    createSliderBar();
//    createStatusBar();
}

void MainWindow::createAcions() {
    exitAction = new QAction("&Exit", this);
    exitAction->setShortcut(QKeySequence::Quit);
    exitAction->setStatusTip("Beendet das Programm");
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::createMenu() {
    fileMenu = menuBar()->addMenu("&Datei");
    fileMenu->addAction(exitAction);
}
