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

QPixmap SlideModel::imageAtPoint(QPoint origin, QPoint size) const {
    int64_t xMin = origin.x();
    int64_t yMin = origin.y();
    QPoint slideSize = dimensions();
    if (xMin < 0 || xMin > slideSize.x() || yMin < 0 || yMin > slideSize.y()) return QPixmap();

    int64_t xMax = xMin + size.x();
    int64_t yMax = yMin + size.y();
    if (xMax > slideSize.x() || yMax > slideSize.y()) return QPixmap();

    // TODO fill with data from the slide
    return QPixmap(size.x(), size.y());
}