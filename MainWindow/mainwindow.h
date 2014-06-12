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
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QToolBar>

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

    void loadImage(const QString& _source);

    QAction* exitAction;
    QAction* openFileAction;

    QMenu* fileMenu;

    QImage* image;

    QToolBar* bottomToolBar;
    QBoxLayout* boxLayout;
    QLabel* label;
    QSlider* slider;
    QPushButton* button;
};

#endif // MAINWINDOW_H
