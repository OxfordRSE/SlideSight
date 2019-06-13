//
// Created by gralee on 11/06/19.
//

#ifndef SLIDESIGHT_SLIDEMODEL_HPP
#define SLIDESIGHT_SLIDEMODEL_HPP

#include <QObject>

namespace sight { class Slide; }

class QPoint;

/**
 * This class provides an interface between the SlideData representing a slide, and the SlideView.
 * It emits a signal indicating that the data represented has changed, and provides an interface for
 * the view to get an image representing a 'window' onto the current slide.
 */
class SlideModel : public QObject {
    Q_OBJECT
public:
    void setSlide(sight::Slide *slide);
    sight::Slide *slide() const;
    QPoint dimensions() const;
signals:
    void slideChanged();
private:
    sight::Slide *theSlide = nullptr;
};


#endif //SLIDESIGHT_SLIDEMODEL_HPP
