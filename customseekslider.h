#ifndef CUSTOMSEEKSLIDER_H
#define CUSTOMSEEKSLIDER_H

#include <QWidget>
#include <QSlider>
#include <QMouseEvent>
#include <QCoreApplication>

class CustomSeekSlider : public QSlider
{
    Q_OBJECT
public:
    CustomSeekSlider(QWidget *parent = nullptr):QSlider(parent) {}

protected:
//  Override the mousePressEvent
    void mousePressEvent(QMouseEvent * event);

signals:
    void seekSliderClicked(double);

public slots:
};

#endif // CUSTOMSEEKSLIDER_H
