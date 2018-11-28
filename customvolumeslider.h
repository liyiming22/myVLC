#ifndef CUSTOMVOLUMESLIDER_H
#define CUSTOMVOLUMESLIDER_H

#include <QWidget>
#include <QSlider>
#include <QMouseEvent>

class CustomVolumeSlider : public QSlider
{
    Q_OBJECT
public:
    CustomVolumeSlider(QWidget *parent = nullptr):QSlider(parent)
    {

    }

protected:
//  Override the mousePressEvent
    void mousePressEvent(QMouseEvent * event);


signals:
    void volumeSliderClicked(int);
};

#endif // CUSTOMVOLUMESLIDER_H
