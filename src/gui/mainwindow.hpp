#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QGraphicsScene;
class QGraphicsView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
private:
    void createScene();
    QGraphicsScene *slideScene;
    QGraphicsView *slideView;
};

#endif // MAINWINDOW_H
