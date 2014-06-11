#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <QImage>
#include <QSlider>
#include <QLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private:
    void createAcions();
    void createMenu();
    void createSliderBar();
    void createImageField();
    void createStatusBar();

    QAction* exitAction;
    QAction* openFileAction;

    QMenu* fileMenu;
};

#endif // MAINWINDOW_H
