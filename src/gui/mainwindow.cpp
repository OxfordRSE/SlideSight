#include "mainwindow.hpp"

#include "SlideView.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setCentralWidget(new SlideView(this));

    setWindowTitle(tr("SIGHT"));
}

