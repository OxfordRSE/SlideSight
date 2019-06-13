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

QSize SlideModel::dimensions() const {
    int64_t width = theSlide ? theSlide->width() : 0;
    int64_t height = theSlide ? theSlide->height() : 0;
    return QSize(width, height);
}

QPixmap SlideModel::imageAtPoint(QRect bounds) const {
    int64_t xMin = bounds.bottomLeft().x();
    int64_t yMin = bounds.bottomLeft().y();
    QSize slideSize = dimensions();
    if (xMin < 0 || xMin > slideSize.width() || yMin < 0 || yMin > slideSize.width()) return QPixmap();

    int64_t xMax = bounds.topRight().x();
    int64_t yMax = bounds.topRight().y();
    if (xMax > slideSize.width() || yMax > slideSize.height()) return QPixmap();

    // TODO fill with data from the slide
    return QPixmap(bounds.size());
}