//
// Created by gralee on 11/06/19.
//

#include "SlideModel.hpp"
#include "SlideData.hpp"

#include <QPixmap>
#include <QPoint>

void SlideModel::setSlide(sight::Slide *slide)
{
    theSlide = slide;
    emit(slideChanged());
}

sight::Slide *SlideModel::slide() const {
    return theSlide;
}

QPoint SlideModel::dimensions() const {
    int64_t width = theSlide ? theSlide->width() : 0;
    int64_t height = theSlide ? theSlide->height() : 0;
    return QPoint(width, height);
}

QPixmap SlideModel::imageAtPoint(QPoint, QPoint) const {
    return QPixmap();
}