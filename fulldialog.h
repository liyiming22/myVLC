#ifndef FULLDIALOG_H
#define FULLDIALOG_H

#include <QDialog>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <QTime>
#include <QDebug>
#include <unistd.h>

namespace Ui {
class fullDialog;
}

class fullDialog : public QDialog
{
    Q_OBJECT

public:
    explicit fullDialog(QWidget *parent = 0);
    ~fullDialog();
    Ui::fullDialog * getUI();
    const long long MAXVALUE = 100000000;

    void updateDurationLabel(int type, QTime time);
    void changeSeek(float pos);

protected:
    bool eventFilter(QObject *, QEvent *);

private:
    Ui::fullDialog *ui;

    int fWidth;
    int fHeight;
    int ctrlHeight;

    bool isHide;

signals:
    void toggle_play_state();
    void seekSlider_clicked(double);
    void seekSlider_moved(int);
    void seekSlider_released();
    void volumeSlider_changed(int);
    void leftClick(bool);
    void rightClick(bool);
    void signal_set_normal_screen();

    void debugTest();

public slots:
    void changePlayIcon(bool);
};

#endif // FULLDIALOG_H
