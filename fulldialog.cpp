#include "fulldialog.h"
#include "ui_fulldialog.h"


fullDialog::fullDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fullDialog)
{
    ui->setupUi(this);

    ui->seekSlider->setMaximum(this->MAXVALUE);
    ui->volumeSlider->setMaximum(200);
    ui->volumeSlider->setValue(50);

    ui->ctrlWidget->setMouseTracking(true);
    ui->ctrlWidget->installEventFilter(this);
    ui->displayWidget->setAttribute(Qt::WA_TransparentForMouseEvents);

    ui->nextButton->setFlat(true);
    ui->playButton->setFlat(true);
    ui->fullButton->setFlat(true);
    ui->lastButton->setFlat(true);



    isHide = true;
    ctrlHeight = 80;
    fWidth = QApplication::desktop()->width();
    fHeight = QApplication::desktop()->height();

    this->resize(QApplication::desktop()->size());

    ui->displayWidget->setGeometry(0, 0, fWidth, fHeight);
    ui->ctrlWidget->setGeometry(0, fHeight - 1, fWidth, ctrlHeight);

    int objectY = (ui->ctrlWidget->height() - ui->lastButton->height()) / 2;
    int objectW = ui->lastButton->width();
    int space = (this->width() - objectW * 5) / 15;
    ui->lastButton->move(space * 5, objectY);
    ui->playButton->move(space * 6 + objectW, objectY);
    ui->nextButton->move(space * 7 + objectW * 2, objectY);
    ui->fullButton->move(space * 10 + objectW * 4, objectY);

    /*------signals and slots------*/
    connect(ui->fullButton, &QPushButton::clicked, this, &fullDialog::signal_set_normal_screen);

    connect(ui->seekSlider, &CustomSeekSlider::seekSliderClicked, this, &fullDialog::seekSlider_clicked);
    connect(ui->seekSlider, &CustomSeekSlider::sliderMoved, this, &fullDialog::seekSlider_moved);
    connect(ui->seekSlider, &CustomSeekSlider::sliderReleased, this, &fullDialog::seekSlider_released);

    connect(ui->volumeSlider, &CustomVolumeSlider::volumeSliderClicked, this, &fullDialog::volumeSlider_changed);
    connect(ui->volumeSlider, &CustomVolumeSlider::sliderMoved, this, &fullDialog::volumeSlider_changed);
}

fullDialog::~fullDialog()
{
    delete ui;
}

Ui::fullDialog *fullDialog::getUI()
{
    return this->ui;
}

void fullDialog::updateDurationLabel(int type, QTime time)
{
    if (!type)
        ui->MediaDurationLabel->setText(time.toString());
    else
        ui->CurrentTimeLabel->setText(time.toString());
}

void fullDialog::changeSeek(float pos)
{
    ui->seekSlider->setValue(pos * MAXVALUE);
}

bool fullDialog::eventFilter(QObject *target, QEvent *event)
{
    if (event->type() == QEvent::MouseMove) {
        QMouseEvent *mousevent = static_cast<QMouseEvent *>(event);
        if (isHide) {
            QPropertyAnimation *animation = new QPropertyAnimation(ui->ctrlWidget, "pos");
            animation->setDuration(200);
            animation->setStartValue(ui->ctrlWidget->pos());
            animation->setEndValue(QPoint(0, fHeight-ctrlHeight));
            animation->start();
//            sleep(0.2);
            isHide = false;
        }
        else {
            if (mousevent->y()>0 && mousevent->y()<20) {
                QPropertyAnimation *animation = new QPropertyAnimation(ui->ctrlWidget, "pos");
                animation->setDuration(200);
                animation->setStartValue(ui->ctrlWidget->pos());
                animation->setEndValue(QPoint(0, fHeight-1));
                animation->start();
//                sleep(0.2);
                isHide = true;
            }
        }
    }
    return QDialog::eventFilter(target, event);
}
