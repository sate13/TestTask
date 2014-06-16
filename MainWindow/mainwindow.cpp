/**
* @file mainwindow.cpp
* @author Marc Satkowski
* @date 16/06/2014
* @version 1.0
*/

#include "mainwindow.h"

MainWindow::MainWindow()
{
    inputImage = NULL;
    outputImage = NULL;
    /* Setzen der Fenster Attribute */
    setMaximumSize(1024, 640);
    setMinimumSize(480, 320);
    setWindowTitle("Probeaufgabe für Cell Tracker");

    /* Erstellen des imageLabels zur Anzeige des Bildes */
    imageLabel = new QLabel;
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    /* Erstellen der ScrollArea damit, wenn das Bild zu groß ist, gescrollt werden kann */
    scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);

    /* Aufruf weitere Funktionen zur Erstellung der Anwendung */
    createAcions();
    createMenu();
    createToolBarElements();
    createToolBar();

    /* Setzen der Elemente des Fensters */
    setCentralWidget(scrollArea);
    addToolBar(Qt::BottomToolBarArea, bottomToolBar);
}

void MainWindow::open() {
    /* Öffnen eines FileDialogs zum Auswählen eines Bildes */
    QString _fileName = QFileDialog::getOpenFileName(this,
                                    tr("Öffne Datei"), QDir::currentPath());
    /* Abfrage ein Pfad und Dateiname angegebn wurde:
     *  wenn nichts -> wird nichts ausgeführt
     * sonst -> wird ein neues Bild erstellt */
    if (!_fileName.isEmpty()) {
        if(inputImage != NULL) {
            inputImage->~QImage();
        }
        inputImage = new QImage(_fileName);
        outputImage = inputImage;
        /* Abfrage ob es schon ein Bild gab:
         *  wenn ja -> wird es gelöscht und der Speicher freigegeben */
        if (inputImage->isNull()) {
            QMessageBox::information(this, tr("Fehler"),
                                     tr("Kann nicht\n%1\nladen.").arg(_fileName));
            return;
        }
        /* Setzen es Bildes in das Label */
        imageLabel->setPixmap(QPixmap::fromImage(*outputImage));
        imageLabel->adjustSize();

        /* Erstellen eines ThreshHolding Objekts zu Schwellenwertberechnung */
        actualThreshHolding.~ThreshHolding();
        actualThreshHolding = ThreshHolding(inputImage);
    }
}

void MainWindow::changeThreshhold() {
    /* Abfrage ob ein Image vorhanden ist und
     * wenn ja -> dann wird eine Fehlermeldung ausgespuckt */
    if(inputImage == NULL) {
        QMessageBox::information(this, "Fehler",
                                 "Es ist kein Bild vorhanden.");
        return;
    }
    /* Sonst wird die Funktion für die Schwellenwerte ausgeführt */
    else {
        QImage _outputImage = actualThreshHolding.changeThreshhold(slider->value());
        imageLabel->setPixmap(QPixmap::fromImage(_outputImage));
    }
    imageLabel->adjustSize();
}

void MainWindow::createAcions() {
    /* Erstellen der Aktion für das benutzen des FileDialoges */
    openFileAction = new QAction("&Open...", this);
    openFileAction->setShortcuts(QKeySequence::Open);
    openFileAction->setStatusTip(tr("Öffnet eine existierende Datei"));
    connect(openFileAction, SIGNAL(triggered()), this, SLOT(open()));

    /* Erstellen der Aktion zum beenden der Anwendung */
    exitAction = new QAction("&Exit", this);
    exitAction->setShortcut(QKeySequence::Quit);
    exitAction->setStatusTip("Beendet das Programm");
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    /* Erstellen der Aktion zum Ändern des Schwellenwertes */
    changeThreshholdAction = new QAction("&Ok", this);
    changeThreshholdAction->setStatusTip("Verändert den Schwellenwert");
    connect(changeThreshholdAction, SIGNAL(triggered()), this, SLOT(changeThreshhold()));
}

void MainWindow::createMenu() {
    /* Erstellen des MenüsBars */
    fileMenu = menuBar()->addMenu("&Datei");
    fileMenu->addAction(openFileAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);
}

void MainWindow::createToolBarElements() {
    /* Erstellen des Sliders */
    slider = new QSlider();
    slider->setOrientation(Qt::Horizontal);
    slider->setMinimum(0);
    slider->setMaximum(255);
    slider->setSingleStep(1);
    slider->setValue(0);

    /* Erstellen der TextArea */
    textArea = new TextArea();
    textArea->setText(QString::number(slider->value()));
    textArea->setFixedWidth(30);
    textArea->setInputMask("999");
    connect(slider, SIGNAL(valueChanged(int)), textArea, SLOT(setNum(int)));

    /* Erstellen des Buttons */
    button = new QPushButton();
    button->setText("&Ok");
    connect(button, SIGNAL(clicked()), changeThreshholdAction, SLOT(trigger()));
}

void MainWindow::createToolBar() {
    /* Erstellen der ToolBar */
    bottomToolBar = new QToolBar("SliderBar");

    bottomToolBar->setLayoutDirection(Qt::LeftToRight);
    bottomToolBar->setMovable(false);

    /* Hinzufügen der Elemente zu ToolBar */
//    bottomToolBar->addWidget(label);
    bottomToolBar->addWidget(textArea);
    bottomToolBar->addWidget(slider);
    bottomToolBar->addWidget(button);
}
