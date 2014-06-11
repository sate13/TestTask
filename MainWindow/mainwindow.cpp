#include "mainwindow.h"

MainWindow::MainWindow()
{
    setMaximumSize(1024, 640);
    setMinimumSize(480, 320);
    setWindowTitle("Probeaufgabe für Cell Tracker");

    createAcions();
    createMenu();
//    createImageField();
//    createSliderBar();
//    createStatusBar();
}

void MainWindow::open() {
    QString fileName = QFileDialog::getOpenFileName(this);
}

void MainWindow::createAcions() {
    openFileAction = new QAction("&Open...", this);
    openFileAction->setShortcuts(QKeySequence::Open);
    openFileAction->setStatusTip(tr("Öffnet eine existierende Datei"));
    connect(openFileAction, SIGNAL(triggered()), this, SLOT(open()));

    exitAction = new QAction("&Exit", this);
    exitAction->setShortcut(QKeySequence::Quit);
    exitAction->setStatusTip("Beendet das Programm");
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::createMenu() {
    fileMenu = menuBar()->addMenu("&Datei");
    fileMenu->addAction(openFileAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);
}

void MainWindow::loadImage(const QString& source) {
    QImage _image (source);

//    if(_image.isNull()) {
//        QString _warningMessage = "Es gibt Probleme mit der Datei "
//                                 + source;
//        QMessageBox::warning(this, "Anwendung", _warningMessage);

//        return;
//    }
}
