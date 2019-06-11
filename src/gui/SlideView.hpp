//
// Created by gralee on 10/06/19.
//

#ifndef SLIDESIGHT_SLIDEVIEW_HPP
#define SLIDESIGHT_SLIDEVIEW_HPP


#include <QWidget>

class QGraphicsScene;
class QGraphicsView;

class SlideView : public QWidget {
    Q_OBJECT
public:
    explicit SlideView(QWidget *parent = nullptr);
private:
    QGraphicsScene *createScene();
    QGraphicsScene *slideScene;
    QGraphicsView *slideView;
};


#endif //SLIDESIGHT_SLIDEVIEW_HPP
