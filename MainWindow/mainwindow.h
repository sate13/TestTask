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
    void createSliderBar();
    void createImageField();
    void createStatusBar();

    void loadImage(const QString& _source);

    QAction* exitAction;
    QAction* openFileAction;

    QMenu* fileMenu;
};

#endif // MAINWINDOW_H
