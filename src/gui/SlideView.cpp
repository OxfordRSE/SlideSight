//
// Created by gralee on 10/06/19.
//

#include "SlideView.hpp"

#include <QGraphicsScene>
#include <QGraphicsView>

SlideView::SlideView(QWidget *parent) :
    QWidget(parent)
{
    slideScene = createScene();
    slideView = new QGraphicsView(slideScene, this);
}

QGraphicsScene *SlideView::createScene()
{
    // TODO configure with a pixmap representation of a slide
    auto scene = new QGraphicsScene(this);
    scene->addText("Hello, world!");
    return scene;
}