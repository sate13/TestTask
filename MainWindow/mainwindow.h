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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void open();

private:
    void createAcions();
    void createMenu();
    void createToolBarElements();
    void createToolBar();
    void createImageField();
    void createStatusBar();

    QAction* exitAction;
    QAction* openFileAction;

    QMenu* fileMenu;

    QScrollArea* scrollArea;
    QLabel* imageLabel;
    QImage* image;

    QToolBar* bottomToolBar;
    QLabel* label;
    QSlider* slider;
    QPushButton* button;
};

#endif // MAINWINDOW_H
