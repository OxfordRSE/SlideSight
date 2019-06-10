#include "mainwindow.hpp"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    createScene();
    slideView = new QGraphicsView(slideScene);
    setCentralWidget(slideView);

    setWindowTitle(tr("SIGHT"));
}

void MainWindow::createScene()
{
    // TODO configure with a pixmap representation of a slide
    slideScene = new QGraphicsScene(this);
    slideScene->addText("Hello, world!");
}