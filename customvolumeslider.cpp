#include "customvolumeslider.h"

void CustomVolumeSlider::mousePressEvent(QMouseEvent *event)
{
//  first avoid the side effects to original slots
    QSlider::mousePressEvent(event);
    double mousePosition = event->pos().x() / (double)width();
    setValue(mousePosition * (maximum() - minimum()) + minimum());
    emit volumeSliderClicked(this->value());
}
