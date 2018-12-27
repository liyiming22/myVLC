#ifndef SYSTEM_H
#define SYSTEM_H

#include <QFileDialog>
#include <QInputDialog>
#include <QDebug>
#include <QTime>
#include <QWidget>
#include <QInputDialog>
#include <QMetaEnum>

#include <VLCQtCore/Common.h>
#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>
#include <VLCQtCore/MediaList.h>
#include <VLCQtCore/MediaListPlayer.h>
#include <VLCQtCore/Audio.h>
#include <VLCQtCore/Video.h>
#include <VLCQtCore/Enums.h>

#include "modules/channelgroup.h"
#include "SimplePlayer.h"
#include "fulldialog.h"
#include "listdialog.h"
#include "barswidget.h"
#include "spectrumanalyzer.h"
#include "ui_SimplePlayer.h"
#include "ui_fulldialog.h"


class System : public QObject
{
    Q_OBJECT

public:
    explicit System(QObject *parent = nullptr);
    ~System();
    enum PlaybackMode {
        Loop,
        Repeat,
        Shuffle,
        Order
    };
    Q_ENUM(PlaybackMode)
    const long long MAXVALUE = 100000000;

private:
    SimplePlayer * videoForm;
    fullDialog * fullForm;
    listDialog * listForm;
    BarsWidget * bars;

    VlcInstance *_instance;
    VlcMedia *_media;
    VlcMediaPlayer *_player;
    VlcMediaPlayer *_fullPlayer;
    VlcAudio * _vlcAudio;
    VlcVideo * _vlcVideo;

    QMediaPlayer * qplayer;
    QAudioProbe * probe;

    SpectrumAnalyzer * m_spectrum_analyzer;

    VlcMediaList * _mediaList;
    QStringList playList;
    int currentMediaIndex;
    int preMediaIndex;
    int nextMediaIndex;
//    bool isLoop;

    QTimer * timer;

    QMetaEnum modeEnum;
    int currentModeIndex;


signals:

public slots:
    void openLocal();
    void toggle_play_state();
    void video_form_changeSeek();
    void full_form_changeSeek();
    void change_video_position(double);
    void seekSlider_moved(double);
    void seekSlider_released();
    void setVolume(int);
    void updateDuration();
    void slot_set_full_screen();
    void slot_set_normal_screen();
    void showList();
    void listFromVideo();
    void listPlay(ChannelGroup *, int);
    void initPlayer();
    void btnRightClick(bool);
    void btnLeftClick(bool);
    void changeChannel(bool);
    void changePos(bool);
    void takeSnapShot();
    void toggleMute();
    void updatePlayMode();
    void updateNextandPre();
    void handleShuffle();
    void handleEnd();
    void normalFormChangeIcon();
    void fullFormChangeIcon();
    void debugTest();
    void openUrl();
};

#endif // SYSTEM_H
