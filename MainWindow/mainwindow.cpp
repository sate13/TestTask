#include "mainwindow.h"

MainWindow::MainWindow()
{
    setMaximumSize(1024, 640);
    setMinimumSize(480, 320);
    setWindowTitle("Probeaufgabe für Cell Tracker");

    createAcions();
    createMenu();
    createToolBarElements();
    createToolBar();

    addToolBar(Qt::BottomToolBarArea, bottomToolBar);
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

void MainWindow::createToolBarElements() {
    label = new QLabel(this);
    label->setText("Hallo");

    slider = new QSlider();
    slider->setOrientation(Qt::Horizontal);
    slider->setMaximum(1);
    slider->setSingleStep(1);
    slider->setMaximum(255);
    slider->setMaximumWidth(320);

    button = new QPushButton();
    button->setText("&Ok");
}

void MainWindow::createToolBar() {
    bottomToolBar = new QToolBar("SliderBar");
    bottomToolBar->setLayoutDirection(Qt::LeftToRight);

    bottomToolBar->setMovable(false);

    bottomToolBar->addWidget(label);
    bottomToolBar->addWidget(slider);
    bottomToolBar->addWidget(button);
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
