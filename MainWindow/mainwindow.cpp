#include "mainwindow.h"

MainWindow::MainWindow()
{
    setMaximumSize(1024, 640);
    setMinimumSize(480, 320);
    setWindowTitle("Probeaufgabe für Cell Tracker");

    imageLabel = new QLabel;
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);

    createAcions();
    createMenu();
    createToolBarElements();
    createToolBar();

    setCentralWidget(scrollArea);
    addToolBar(Qt::BottomToolBarArea, bottomToolBar);
}

void MainWindow::open() {
    QString _fileName = QFileDialog::getOpenFileName(this,
                                    tr("Öffne Datei"), QDir::currentPath());
    if (!_fileName.isEmpty()) {
        inputImage = new QImage(_fileName);
        outputImage = inputImage;
        if (inputImage->isNull()) {
            QMessageBox::information(this, tr("Image Viewer"),
                                     tr("Cannot load %1.").arg(_fileName));
            return;
        }
        imageLabel->setPixmap(QPixmap::fromImage(*outputImage));
        imageLabel->adjustSize();

//        if(&actualThreshHolding != nullptr) {
//            actualThreshHolding.~ThreshHolding();
//            &actualThreshHolding = nullptr;
//        }
        actualThreshHolding.~ThreshHolding();
        actualThreshHolding = ThreshHolding(*inputImage);
    }
}

void MainWindow::changeThreshhold() {

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

    changeThreshholdAction = new QAction("&Ok", bottomToolBar);
    changeThreshholdAction->setStatusTip("Verändert den Schwellenwert");
    connect(changeThreshholdAction, SIGNAL(triggered()), this, SLOT(changeThreshhold()));
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
    slider->setMinimum(1);
    slider->setMaximum(255);
    slider->setValue(1);
    slider->setSingleStep(1);

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