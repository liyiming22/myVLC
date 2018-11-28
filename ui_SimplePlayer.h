/********************************************************************************
** Form generated from reading UI file 'SimplePlayer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLEPLAYER_H
#define UI_SIMPLEPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <VLCQtWidgets/WidgetVideo.h>
#include "customseekslider.h"
#include "customvolumeslider.h"

QT_BEGIN_NAMESPACE

class Ui_SimplePlayer
{
public:
    QAction *actionQuit;
    QAction *actionPause;
    QAction *actionStop;
    QAction *actionOpenLocal;
    QAction *actionOpenUrl;
    QAction *actionAbout;
    QAction *actionsnapshut;
    QAction *actionfull;
    QAction *action_mute;
    QAction *action_mode_1;
    QAction *action_list;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    VlcWidgetVideo *video;
    QHBoxLayout *horizontalLayout_2;
    QLabel *CurrentTimeLabel;
    CustomSeekSlider *seekSlider;
    QLabel *MediaDurationLabel;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPrevious;
    QPushButton *stop;
    QPushButton *pause;
    QPushButton *btnNext;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *fullButton;
    QPushButton *snapshotButton;
    QPushButton *modeButton;
    QPushButton *volumeButton;
    CustomVolumeSlider *volumeSlider;
    QPushButton *listButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuMedia;
    QMenu *menu_2;
    QMenu *menuHelp;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SimplePlayer)
    {
        if (SimplePlayer->objectName().isEmpty())
            SimplePlayer->setObjectName(QStringLiteral("SimplePlayer"));
        SimplePlayer->resize(523, 416);
        SimplePlayer->setMinimumSize(QSize(523, 0));
        actionQuit = new QAction(SimplePlayer);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionPause = new QAction(SimplePlayer);
        actionPause->setObjectName(QStringLiteral("actionPause"));
        actionStop = new QAction(SimplePlayer);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        actionOpenLocal = new QAction(SimplePlayer);
        actionOpenLocal->setObjectName(QStringLiteral("actionOpenLocal"));
        actionOpenUrl = new QAction(SimplePlayer);
        actionOpenUrl->setObjectName(QStringLiteral("actionOpenUrl"));
        actionAbout = new QAction(SimplePlayer);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionsnapshut = new QAction(SimplePlayer);
        actionsnapshut->setObjectName(QStringLiteral("actionsnapshut"));
        actionfull = new QAction(SimplePlayer);
        actionfull->setObjectName(QStringLiteral("actionfull"));
        action_mute = new QAction(SimplePlayer);
        action_mute->setObjectName(QStringLiteral("action_mute"));
        action_mode_1 = new QAction(SimplePlayer);
        action_mode_1->setObjectName(QStringLiteral("action_mode_1"));
        action_list = new QAction(SimplePlayer);
        action_list->setObjectName(QStringLiteral("action_list"));
        centralwidget = new QWidget(SimplePlayer);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        video = new VlcWidgetVideo(centralwidget);
        video->setObjectName(QStringLiteral("video"));
        video->setMinimumSize(QSize(0, 250));
        video->setSizeIncrement(QSize(0, 0));
        video->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(video);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        CurrentTimeLabel = new QLabel(centralwidget);
        CurrentTimeLabel->setObjectName(QStringLiteral("CurrentTimeLabel"));

        horizontalLayout_2->addWidget(CurrentTimeLabel);

        seekSlider = new CustomSeekSlider(centralwidget);
        seekSlider->setObjectName(QStringLiteral("seekSlider"));
        seekSlider->setEnabled(true);
        seekSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(seekSlider);

        MediaDurationLabel = new QLabel(centralwidget);
        MediaDurationLabel->setObjectName(QStringLiteral("MediaDurationLabel"));

        horizontalLayout_2->addWidget(MediaDurationLabel);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnPrevious = new QPushButton(centralwidget);
        btnPrevious->setObjectName(QStringLiteral("btnPrevious"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/player of icon/image/\345\267\246.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrevious->setIcon(icon);
        btnPrevious->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(btnPrevious);

        stop = new QPushButton(centralwidget);
        stop->setObjectName(QStringLiteral("stop"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/player of icon/image/\345\201\234\346\255\242.ico"), QSize(), QIcon::Normal, QIcon::Off);
        stop->setIcon(icon1);
        stop->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(stop);

        pause = new QPushButton(centralwidget);
        pause->setObjectName(QStringLiteral("pause"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/player of icon/image/\346\232\202\345\201\234.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pause->setIcon(icon2);
        pause->setIconSize(QSize(32, 32));
        pause->setCheckable(false);
        pause->setFlat(false);

        horizontalLayout->addWidget(pause);

        btnNext = new QPushButton(centralwidget);
        btnNext->setObjectName(QStringLiteral("btnNext"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/player of icon/image/\345\217\263.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnNext->setIcon(icon3);
        btnNext->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(btnNext);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        fullButton = new QPushButton(centralwidget);
        fullButton->setObjectName(QStringLiteral("fullButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/player of icon/image/\345\205\250\345\261\217.ico"), QSize(), QIcon::Normal, QIcon::Off);
        fullButton->setIcon(icon4);
        fullButton->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(fullButton);

        snapshotButton = new QPushButton(centralwidget);
        snapshotButton->setObjectName(QStringLiteral("snapshotButton"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/player of icon/image/\346\210\252\345\233\276.ico"), QSize(), QIcon::Normal, QIcon::Off);
        snapshotButton->setIcon(icon5);
        snapshotButton->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(snapshotButton);

        modeButton = new QPushButton(centralwidget);
        modeButton->setObjectName(QStringLiteral("modeButton"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/player of icon/image/\351\241\272\345\272\217\346\222\255\346\224\276.ico"), QSize(), QIcon::Normal, QIcon::Off);
        modeButton->setIcon(icon6);
        modeButton->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(modeButton);

        volumeButton = new QPushButton(centralwidget);
        volumeButton->setObjectName(QStringLiteral("volumeButton"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/player of icon/image/\351\237\263\351\207\217.ico"), QSize(), QIcon::Normal, QIcon::Off);
        volumeButton->setIcon(icon7);

        horizontalLayout->addWidget(volumeButton);

        volumeSlider = new CustomVolumeSlider(centralwidget);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(volumeSlider);

        listButton = new QPushButton(centralwidget);
        listButton->setObjectName(QStringLiteral("listButton"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/player of icon/image/\345\210\227\350\241\250.ico"), QSize(), QIcon::Normal, QIcon::Off);
        listButton->setIcon(icon8);
        listButton->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(listButton);


        verticalLayout->addLayout(horizontalLayout);

        SimplePlayer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SimplePlayer);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 523, 20));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuMedia = new QMenu(menubar);
        menuMedia->setObjectName(QStringLiteral("menuMedia"));
        menu_2 = new QMenu(menuMedia);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        SimplePlayer->setMenuBar(menubar);
        statusbar = new QStatusBar(SimplePlayer);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SimplePlayer->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuMedia->menuAction());
        menubar->addAction(menu->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpenLocal);
        menuFile->addAction(actionOpenUrl);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuMedia->addAction(actionPause);
        menuMedia->addAction(action_mute);
        menuMedia->addAction(actionStop);
        menuMedia->addAction(actionfull);
        menuMedia->addAction(menu_2->menuAction());
        menu_2->addAction(action_mode_1);
        menuHelp->addAction(actionAbout);
        menu->addAction(action_list);
        menu->addAction(actionsnapshut);

        retranslateUi(SimplePlayer);
        QObject::connect(actionQuit, SIGNAL(triggered()), SimplePlayer, SLOT(close()));

        QMetaObject::connectSlotsByName(SimplePlayer);
    } // setupUi

    void retranslateUi(QMainWindow *SimplePlayer)
    {
        SimplePlayer->setWindowTitle(QApplication::translate("SimplePlayer", "Demo Player", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("SimplePlayer", "\351\200\200\345\207\272", Q_NULLPTR));
        actionPause->setText(QApplication::translate("SimplePlayer", "\346\232\202\345\201\234", Q_NULLPTR));
        actionStop->setText(QApplication::translate("SimplePlayer", "\345\201\234\346\255\242", Q_NULLPTR));
        actionOpenLocal->setText(QApplication::translate("SimplePlayer", "\346\211\223\345\274\200\346\234\254\345\234\260", Q_NULLPTR));
        actionOpenUrl->setText(QApplication::translate("SimplePlayer", "\346\211\223\345\274\200\347\275\221\347\273\234\346\265\201", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("SimplePlayer", "\345\205\263\344\272\216", Q_NULLPTR));
        actionsnapshut->setText(QApplication::translate("SimplePlayer", "\346\210\252\345\233\276", Q_NULLPTR));
        actionfull->setText(QApplication::translate("SimplePlayer", "\345\205\250\345\261\217", Q_NULLPTR));
        action_mute->setText(QApplication::translate("SimplePlayer", "\351\235\231\351\237\263", Q_NULLPTR));
        action_mode_1->setText(QApplication::translate("SimplePlayer", "\351\241\272\345\272\217\346\222\255\346\224\276", Q_NULLPTR));
        action_list->setText(QApplication::translate("SimplePlayer", "\346\211\223\345\274\200\346\222\255\346\224\276\345\210\227\350\241\250", Q_NULLPTR));
        CurrentTimeLabel->setText(QApplication::translate("SimplePlayer", "TextLabel", Q_NULLPTR));
        MediaDurationLabel->setText(QApplication::translate("SimplePlayer", "TextLabel", Q_NULLPTR));
        btnPrevious->setText(QString());
        stop->setText(QString());
        pause->setText(QString());
        btnNext->setText(QString());
        fullButton->setText(QString());
        snapshotButton->setText(QString());
        modeButton->setText(QString());
        volumeButton->setText(QString());
        listButton->setText(QString());
        menuFile->setTitle(QApplication::translate("SimplePlayer", "\346\226\207\344\273\266", Q_NULLPTR));
        menuMedia->setTitle(QApplication::translate("SimplePlayer", "\345\252\222\344\275\223", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("SimplePlayer", "\346\222\255\346\224\276\346\250\241\345\274\217", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("SimplePlayer", "\345\270\256\345\212\251", Q_NULLPTR));
        menu->setTitle(QApplication::translate("SimplePlayer", "\345\267\245\345\205\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SimplePlayer: public Ui_SimplePlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLEPLAYER_H
