/**
* @file mainwindow.h
* @author Marc Satkowski
* @date 13/06/2014
* @version 1.0
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <QImage>
#include <QSlider>
#include <QLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QLabel>
#include <QPushButton>
#include <QToolBar>
#include <QScrollArea>

#include "Treshholding/threshholding.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void open();
    void changeThreshhold();

private:
    void createAcions();
    void createMenu();
    void createToolBarElements();
    void createToolBar();
    void createImageField();
    void createStatusBar();

    QAction* exitAction;
    QAction* openFileAction;
    QAction* changeThreshholdAction;

    QMenu* fileMenu;

    QScrollArea* scrollArea;
    QLabel* imageLabel;
    QImage* inputImage;
    QImage* outputImage;

    QToolBar* bottomToolBar;
    QLabel* label;
    QSlider* slider;
    QPushButton* button;

    ThreshHolding actualThreshHolding;
};

#endif // MAINWINDOW_H
