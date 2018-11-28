#include "system.h"

System::System(QObject *parent) : QObject(parent)
{
    videoForm = new SimplePlayer;
    fullForm = new fullDialog;
    listForm = new listDialog;
    videoForm->move(550, 350);
    videoForm->show();
    listFromVideo();

    _instance = new VlcInstance(VlcCommon::args(), this);
    _player = new VlcMediaPlayer(_instance);
    _fullPlayer = new VlcMediaPlayer(_instance);
    _player->setVideoWidget(videoForm->getUI()->video);
    _mediaList = new VlcMediaList(_instance);
    currentMediaIndex = 0;
    preMediaIndex = 0;
    nextMediaIndex = 0;
    currentModeIndex = 0;
//    isLoop = true;
    modeEnum = QMetaEnum::fromType<System::PlaybackMode>();

    connect(videoForm, &SimplePlayer::open_local_files, this, &System::openLocal);
    connect(videoForm, &SimplePlayer::toggle_play_state, this, &System::toggle_play_state);
    connect(videoForm, &SimplePlayer::debugTest, this, &System::debugTest);
    connect(videoForm, &SimplePlayer::signal_set_full_screen, this, &System::slot_set_full_screen);
    connect(videoForm, &SimplePlayer::seekSlider_clicked, this, &System::change_video_position);
    connect(videoForm, &SimplePlayer::seekSlider_moved, this, &System::seekSlider_moved);
    connect(videoForm, &SimplePlayer::seekSlider_released, this, &System::seekSlider_released);
    connect(videoForm, &SimplePlayer::volumeSlider_changed, this, &System::setVolume);
    connect(videoForm, &SimplePlayer::showList, this, &System::showList);
    connect(videoForm, &SimplePlayer::takeSnapShot, this, &System::takeSnapShot);
    connect(videoForm, &SimplePlayer::toggleMute, this, &System::toggleMute);

    connect(videoForm, &SimplePlayer::recordPos, listForm, &listDialog::recordPos);
    connect(videoForm, &SimplePlayer::moveDif, listForm, &listDialog::moveDif);

    connect(videoForm, &SimplePlayer::leftClick, this, &System::btnLeftClick);
    connect(videoForm, &SimplePlayer::rightClick, this, &System::btnRightClick);

    connect(videoForm, &SimplePlayer::modeChange, this, &System::updatePlayMode);
    connect(videoForm, &SimplePlayer::modeChange, this, &System::updateNextandPre);
    connect(_player, &VlcMediaPlayer::opening, this, &System::updateNextandPre);
    connect(_player, &VlcMediaPlayer::end, this, &System::handleEnd);

    connect(fullForm, &fullDialog::signal_set_normal_screen, this, &System::slot_set_normal_screen);
    connect(fullForm, &fullDialog::seekSlider_clicked, this, &System::change_video_position);
    connect(fullForm, &fullDialog::seekSlider_moved, this, &System::seekSlider_moved);
    connect(fullForm, &fullDialog::seekSlider_released, this, &System::seekSlider_released);
    connect(fullForm, &fullDialog::volumeSlider_changed, this, &System::setVolume);
    connect(fullForm, &fullDialog::leftClick, this, &System::btnLeftClick);
    connect(fullForm, &fullDialog::rightClick, this, &System::btnRightClick);

    connect(listForm, &listDialog::listPlay, this, &System::listPlay);

}

System::~System()
{
    delete videoForm;
    delete fullForm;
    delete listForm;
    delete _instance;
    delete _player;
    delete _fullPlayer;
    delete _mediaList;
    delete timer;
}

void System::initPlayer()
{
    timer = new QTimer;
    timer->setInterval(1000);
    timer->start();
    videoForm->activeSlider();
    connect(this->timer, &QTimer::timeout, this, &System::video_form_changeSeek);
    connect(this->timer, &QTimer::timeout, this, &System::full_form_changeSeek);
    connect(this->timer, &QTimer::timeout, this, &System::updateDuration);
    _vlcAudio = _player->audio();
    _vlcAudio->setVolume(50);
}

void System::btnRightClick(bool isNext)
{
    changeChannel(isNext);
}

void System::btnLeftClick(bool isNext)
{
    changePos(isNext);
}

void System::changeChannel(bool isNext)
{
    qDebug() << "changeChannel" << isNext << endl;
    currentMediaIndex = isNext? nextMediaIndex:preMediaIndex;
    initPlayer();
    _player->open(_mediaList->at(currentMediaIndex));
//    _fullPlayer->open(_mediaList->at(currentMediaIndex));
//    updateNextandPre();
}

void System::changePos(bool isNext)
{
    qDebug() << "changePos" << isNext << endl;
    double step = isNext? 0.01:-0.01;
    _player->setPosition(_player->position() + step);
    _fullPlayer->setPosition(_fullPlayer->position() + step);
}

void System::takeSnapShot()
{
    _player->pause();
    _vlcVideo = new VlcVideo(_player);
    QString dir = QFileDialog::getExistingDirectory(videoForm, "选择保存的目录",
                                                    "/home/yeoman",
                                                    QFileDialog::ShowDirsOnly);
    _vlcVideo->takeSnapshot(dir);
    qDebug() << "take a snap shot" << endl;
    delete _vlcVideo;
    _player->play();
}

void System::toggleMute()
{
    _vlcAudio->toggleMute();
}

void System::updatePlayMode()
{
    ++currentModeIndex;
    currentModeIndex %= modeEnum.keyCount();
}

void System::updateNextandPre()
{
    qDebug() << "update next and previous" << endl;
    PlaybackMode thisMode = PlaybackMode(currentModeIndex);
    switch (thisMode) {
        case Loop:
            nextMediaIndex = (currentMediaIndex + 1) % _mediaList->count();
            preMediaIndex = currentMediaIndex;
            break;
        case Repeat:
            nextMediaIndex = currentMediaIndex;
            preMediaIndex = currentMediaIndex;
            break;
        case Shuffle:
            handleShuffle();
            break;
        case Order:
            nextMediaIndex = (currentMediaIndex + 1) % _mediaList->count();
            preMediaIndex = currentMediaIndex;
            break;
        default:
            break;
    }
}

void System::handleShuffle()
{
    preMediaIndex = currentMediaIndex;
    nextMediaIndex = currentMediaIndex;
    int upperBound = _mediaList->count() - 1;
    int lowerBound = 0;
    srand((unsigned)time(NULL));
    while(nextMediaIndex == currentMediaIndex)
        nextMediaIndex = rand() % (upperBound - lowerBound + 1) + lowerBound;
}

void System::handleEnd()
{
    PlaybackMode thisMode = PlaybackMode(currentModeIndex);
    if (thisMode == Order && currentMediaIndex == _mediaList->count() - 1)
        _player->stop();
    else    changeChannel(true);
}

void System::openLocal()
{
    playList =
            QFileDialog :: getOpenFileNames(videoForm, "Open file",
                                         "/home/yeoman",
                                         "Multimedia files(*)");
    if ( 0 == playList.length() )    return;

    for ( int index = 0; index < playList.length(); ++index ) {
        _media = new VlcMedia(playList.at(index), true, _instance);
        _mediaList->addMedia(_media);
    }
    initPlayer();
    _player->open(_mediaList->at(currentMediaIndex));
}

void System::listPlay(ChannelGroup *group, int index)
{
    for ( int index = 0; index < group->count(); ++index ) {
        _media = new VlcMedia(group->getChannel(index)->getAddress(), true, _instance);
        _mediaList->addMedia(_media);
    }
    initPlayer();
    currentMediaIndex = index;
    _player->open(_mediaList->at(currentMediaIndex));
//    updateNextandPre();
    qDebug() << _mediaList->count();
}

void System::toggle_play_state()
{
    _player->togglePause();
    _fullPlayer->togglePause();
}

void System::video_form_changeSeek()
{
    videoForm->changeSeek(_player->position());
}

void System::full_form_changeSeek()
{
    fullForm->changeSeek(_fullPlayer->position());
}

void System::change_video_position(double val)
{
    _player->setPosition(val);
    _fullPlayer->setPosition(val);
}

void System::seekSlider_moved(double val)
{
    timer->stop();
    this->change_video_position((double)val / MAXVALUE);
}

void System::seekSlider_released()
{
    timer->start();
}

void System::setVolume(int val)
{
    _vlcAudio->setVolume(val);
}

void System::updateDuration()
{
    qint64 duration = _mediaList->at(currentMediaIndex)->duration();
    int seconds = (duration/1000) % 60;
    int minutes = (duration/60000) % 60;
    int hours = (duration/3600000) % 24;
    QTime time(hours, minutes,seconds);
    videoForm->updateDurationLabel(0, time);
    fullForm->updateDurationLabel(0, time);

    qint64 thisTime = duration * _player->position();
    seconds = (thisTime / 1000) % 60;
    minutes = (thisTime / 60000) % 60;
    hours = (thisTime / 3600000) % 24;
    QTime currenTime(hours, minutes, seconds);
    videoForm->updateDurationLabel(1, currenTime);
    fullForm->updateDurationLabel(1, currenTime);
}

void System::slot_set_full_screen()
{
    _player->pause();
    videoForm->hide();
    fullForm->showFullScreen();
    _fullPlayer->setVideoWidget(fullForm->getUI()->displayWidget);
    _fullPlayer->open(_mediaList->at(currentMediaIndex));
    _fullPlayer->setPosition(_player->position());
}

void System::slot_set_normal_screen()
{
    _fullPlayer->pause();
    _player->setPosition(_fullPlayer->position());
    fullForm->hide();
    listFromVideo();
    videoForm->show();
    _player->play();
}

void System::showList()
{
    listFromVideo();
    if ( listForm->isHidden() ) listForm->show();
    else    listForm->hide();
}

void System::listFromVideo()
{
    int x = videoForm->x() + videoForm->width();
    int y = videoForm->y() + (videoForm->height() - listForm->height()) / 2;
//    qDebug() << x << " " << y << endl;
    listForm->move(x, y);
}

void System::debugTest()
{
    qDebug() << modeEnum.valueToKey(currentModeIndex) << endl;
}
