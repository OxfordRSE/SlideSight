//
// Created by gralee on 11/06/19.
//

#include "SlideModel.hpp"
#include "SlideData.hpp"
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
    return QPoint(theSlide->width(), theSlide->height());
}