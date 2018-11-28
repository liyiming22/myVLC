/********************************************************************************
** Form generated from reading UI file 'fulldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FULLDIALOG_H
#define UI_FULLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <VLCQtWidgets/WidgetVideo.h>
#include "customseekslider.h"
#include "customvolumeslider.h"

QT_BEGIN_NAMESPACE

class Ui_fullDialog
{
public:
    VlcWidgetVideo *displayWidget;
    QWidget *ctrlWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *CurrentTimeLabel;
    CustomSeekSlider *seekSlider;
    QLabel *MediaDurationLabel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *lastButton;
    QPushButton *playButton;
    QPushButton *nextButton;
    QPushButton *fullButton;
    CustomVolumeSlider *volumeSlider;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *fullDialog)
    {
        if (fullDialog->objectName().isEmpty())
            fullDialog->setObjectName(QStringLiteral("fullDialog"));
        fullDialog->resize(618, 380);
        displayWidget = new VlcWidgetVideo(fullDialog);
        displayWidget->setObjectName(QStringLiteral("displayWidget"));
        displayWidget->setGeometry(QRect(130, 40, 331, 211));
        displayWidget->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        ctrlWidget = new QWidget(fullDialog);
        ctrlWidget->setObjectName(QStringLiteral("ctrlWidget"));
        ctrlWidget->setGeometry(QRect(120, 260, 351, 101));
        ctrlWidget->setStyleSheet(QLatin1String("background-color: rgb(238, 238, 236);\n"
"setWindowOpacity:(0.7); \n"
""));
        verticalLayout = new QVBoxLayout(ctrlWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        CurrentTimeLabel = new QLabel(ctrlWidget);
        CurrentTimeLabel->setObjectName(QStringLiteral("CurrentTimeLabel"));

        horizontalLayout_2->addWidget(CurrentTimeLabel);

        seekSlider = new CustomSeekSlider(ctrlWidget);
        seekSlider->setObjectName(QStringLiteral("seekSlider"));
        seekSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(seekSlider);

        MediaDurationLabel = new QLabel(ctrlWidget);
        MediaDurationLabel->setObjectName(QStringLiteral("MediaDurationLabel"));

        horizontalLayout_2->addWidget(MediaDurationLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        lastButton = new QPushButton(ctrlWidget);
        lastButton->setObjectName(QStringLiteral("lastButton"));
        lastButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/player of icon/image/\345\267\246.ico"), QSize(), QIcon::Normal, QIcon::Off);
        lastButton->setIcon(icon);
        lastButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(lastButton);

        playButton = new QPushButton(ctrlWidget);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/player of icon/image/\346\232\202\345\201\234.ico"), QSize(), QIcon::Normal, QIcon::Off);
        playButton->setIcon(icon1);
        playButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(playButton);

        nextButton = new QPushButton(ctrlWidget);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/player of icon/image/\345\217\263.ico"), QSize(), QIcon::Normal, QIcon::Off);
        nextButton->setIcon(icon2);
        nextButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(nextButton);

        fullButton = new QPushButton(ctrlWidget);
        fullButton->setObjectName(QStringLiteral("fullButton"));
        fullButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/player of icon/image/\345\205\250\345\261\217.ico"), QSize(), QIcon::Normal, QIcon::Off);
        fullButton->setIcon(icon3);
        fullButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(fullButton);

        volumeSlider = new CustomVolumeSlider(ctrlWidget);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setMaximumSize(QSize(100, 50));
        volumeSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(volumeSlider);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(fullDialog);

        QMetaObject::connectSlotsByName(fullDialog);
    } // setupUi

    void retranslateUi(QDialog *fullDialog)
    {
        fullDialog->setWindowTitle(QApplication::translate("fullDialog", "Dialog", Q_NULLPTR));
        CurrentTimeLabel->setText(QApplication::translate("fullDialog", "TextLabel", Q_NULLPTR));
        MediaDurationLabel->setText(QApplication::translate("fullDialog", "TextLabel", Q_NULLPTR));
        lastButton->setText(QString());
        playButton->setText(QString());
        nextButton->setText(QString());
        fullButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class fullDialog: public Ui_fullDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FULLDIALOG_H
