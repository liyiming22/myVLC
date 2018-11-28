#include "customseekslider.h"
#include <QDebug>

void CustomSeekSlider::mousePressEvent(QMouseEvent *event)
{
//  first avoid the side effects to original slots
    QSlider::mousePressEvent(event);
    double mousePosition = event->pos().x() / (double)width();
    setValue(mousePosition * (maximum() - minimum()) + minimum());
    emit seekSliderClicked((double)this->value() / 100000000);
}
