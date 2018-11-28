#include "SimplePlayer.h"
#include "ui_SimplePlayer.h"

SimplePlayer::SimplePlayer(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::SimplePlayer)
{
    ui->setupUi(this);
    aboutWidget = new aboutDialog();
    ui->seekSlider->setMaximum(this->MAXVALUE);
    ui->seekSlider->setEnabled(false);
    ui->volumeSlider->setMaximum(200);
    ui->volumeSlider->setValue(50);
    ui->volumeSlider->setEnabled(false);
    ui->CurrentTimeLabel->setText("--:--:--");
    ui->MediaDurationLabel->setText("--:--:--");
    ui->btnNext->installEventFilter(this);
    ui->btnPrevious->installEventFilter(this);
    connect(ui->actionOpenLocal, &QAction::triggered, this, &SimplePlayer::open_local_files);
    connect(ui->actionPause, &QAction::triggered, this, &SimplePlayer::toggle_play_state);
    connect(ui->actionAbout, &QAction::triggered, aboutWidget, &aboutDialog::show);
    connect(ui->actionsnapshut, &QAction::triggered, this, &SimplePlayer::takeSnapShot);
    connect(ui->actionfull, &QAction::triggered, this, &SimplePlayer::signal_set_full_screen);
    connect(ui->action_mute, &QAction::triggered, this, &SimplePlayer::toggleMute);
    connect(ui->action_list, &QAction::triggered, this, &SimplePlayer::showList);




    connect(ui->pause, &QPushButton::clicked, this, &SimplePlayer::toggle_play_state);
    connect(ui->pause, &QPushButton::clicked, this, &SimplePlayer::debugTest);
    connect(ui->fullButton, &QPushButton::clicked, this, &SimplePlayer::signal_set_full_screen);
    connect(ui->listButton, &QPushButton::clicked, this, &SimplePlayer::showList);
    connect(ui->snapshotButton, &QPushButton::clicked, this, &SimplePlayer::takeSnapShot);
    connect(ui->volumeButton, &QPushButton::clicked, this, &SimplePlayer::toggleMute);

    connect(ui->seekSlider, &CustomSeekSlider::seekSliderClicked, this, &SimplePlayer::seekSlider_clicked);
    connect(ui->seekSlider, &CustomSeekSlider::sliderMoved, this, &SimplePlayer::seekSlider_moved);
    connect(ui->seekSlider, &CustomSeekSlider::sliderReleased, this, &SimplePlayer::seekSlider_released);

    connect(ui->volumeSlider, &CustomVolumeSlider::volumeSliderClicked, this, &SimplePlayer::volumeSlider_changed);
    connect(ui->volumeSlider, &CustomVolumeSlider::sliderMoved, this, &SimplePlayer::volumeSlider_changed);

    connect(ui->modeButton, &QPushButton::clicked, this, &SimplePlayer::modeChange);
}

SimplePlayer::~SimplePlayer()
{
    delete ui;
    delete aboutWidget;
}

Ui:: SimplePlayer * SimplePlayer::getUI()
{
    return this->ui;
}

void SimplePlayer::changeSeek(float pos)
{
    ui->seekSlider->setValue(pos * MAXVALUE);
}

void SimplePlayer::updateDurationLabel(int type, QTime time)
{
    if (!type)
        ui->MediaDurationLabel->setText(time.toString());
    else
        ui->CurrentTimeLabel->setText(time.toString());
}

void SimplePlayer::activeSlider()
{
    ui->seekSlider->setEnabled(true);
    ui->volumeSlider->setEnabled(true);
}

void SimplePlayer::mouseDoubleClickEvent(QMouseEvent* event)
{
    //if(event->button()==Qt::LeftButton)



}

bool SimplePlayer::eventFilter(QObject * target, QEvent * event)
{
    if (event->type()==QEvent::MouseButtonPress) {
        if (target == ui->btnNext || target == ui->btnPrevious) {
            bool isNext = target == ui->btnNext;
            QMouseEvent *ev = (QMouseEvent*)event;
            if (ev->button() == Qt::LeftButton) emit leftClick(isNext);
            else    emit rightClick(isNext);
        }
    }
    return QMainWindow::eventFilter(target, event);
}
