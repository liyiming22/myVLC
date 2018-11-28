/*
* VLC-Qt Simple Player
* Copyright (C)
*/

#ifndef SIMPLEPLAYER_H_
#define SIMPLEPLAYER_H_

#include <QMainWindow>
#include <QTime>
#include <QDebug>
#include <QMouseEvent>
#include "customseekslider.h"
#include "widget/aboutdialog.h"

namespace Ui {
    class SimplePlayer;
}

class SimplePlayer : public QMainWindow
{
    Q_OBJECT
public:
    explicit SimplePlayer(QWidget *parent = 0);
    ~SimplePlayer();
    Ui::SimplePlayer * getUI();
    void changeSeek(float pos);
    const long long MAXVALUE = 100000000;

public slots:
    void updateDurationLabel(int type, QTime time);
    void activeSlider();
    void mouseDoubleClickEvent(QMouseEvent* event);

private:
    Ui::SimplePlayer *ui;

    aboutDialog *aboutWidget;

    bool isDrag;
    QPoint mouse;
    QPoint win;

protected:
    bool eventFilter(QObject *, QEvent *);

signals:
    void open_local_files();
    void toggle_play_state();
    void seekSlider_clicked(double);
    void seekSlider_moved(int);
    void seekSlider_released();
    void volumeSlider_changed(int);
    void signal_set_full_screen();
    void showList();
    void takeSnapShot();
    void toggleMute();

    void recordPos();
    void moveDif(QPoint);

    void debugTest();

    void leftClick(bool);
    void rightClick(bool);

    void modeChange();
};

#endif // SIMPLEPLAYER_H_
