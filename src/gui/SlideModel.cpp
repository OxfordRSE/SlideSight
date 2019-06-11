//
// Created by gralee on 11/06/19.
//

#include "SlideModel.hpp"
#include "SlideData.hpp"
#include <QPoint>

void SlideModel::setSlideData(sight::SlideData *slideData)
{
    theSlide = slideData;
    emit(slideChanged(slideData));
}

sight::SlideData *SlideModel::slideData() {
    return theSlide;
}

QPoint SlideModel::dimensions() {
    return QPoint(theSlide->width(), theSlide->height());
}