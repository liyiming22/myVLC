/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_aboutDialog
{
public:
    QPushButton *pushButton;
    QLabel *icoLabel;
    QLabel *titleLabel;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QDialog *aboutDialog)
    {
        if (aboutDialog->objectName().isEmpty())
            aboutDialog->setObjectName(QStringLiteral("aboutDialog"));
        aboutDialog->resize(292, 203);
        aboutDialog->setMinimumSize(QSize(292, 203));
        aboutDialog->setMaximumSize(QSize(292, 203));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        aboutDialog->setFont(font);
        pushButton = new QPushButton(aboutDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 160, 80, 27));
        icoLabel = new QLabel(aboutDialog);
        icoLabel->setObjectName(QStringLiteral("icoLabel"));
        icoLabel->setGeometry(QRect(15, 60, 90, 90));
        icoLabel->setPixmap(QPixmap(QString::fromUtf8(":/\345\233\276\347\211\207/steamWorld.png")));
        icoLabel->setScaledContents(true);
        titleLabel = new QLabel(aboutDialog);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setGeometry(QRect(95, 15, 151, 24));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        titleLabel->setFont(font1);
        label_3 = new QLabel(aboutDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 50, 131, 19));
        label_4 = new QLabel(aboutDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(120, 70, 161, 19));
        label_5 = new QLabel(aboutDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(120, 110, 151, 19));
        label_6 = new QLabel(aboutDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(120, 90, 181, 19));
        label_7 = new QLabel(aboutDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(120, 130, 161, 19));
        label_8 = new QLabel(aboutDialog);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 163, 161, 19));

        retranslateUi(aboutDialog);

        QMetaObject::connectSlotsByName(aboutDialog);
    } // setupUi

    void retranslateUi(QDialog *aboutDialog)
    {
        aboutDialog->setWindowTitle(QApplication::translate("aboutDialog", "\345\205\263\344\272\216", Q_NULLPTR));
        pushButton->setText(QApplication::translate("aboutDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        icoLabel->setText(QString());
        titleLabel->setText(QApplication::translate("aboutDialog", "SimplePlayerV1.0", Q_NULLPTR));
        label_3->setText(QApplication::translate("aboutDialog", "IDE\357\274\232 Qt Creator", Q_NULLPTR));
        label_4->setText(QApplication::translate("aboutDialog", "\347\274\226\347\250\213\346\241\206\346\236\266\357\274\232 Qt 5.11.0", Q_NULLPTR));
        label_5->setText(QApplication::translate("aboutDialog", "\346\265\201\345\252\222\344\275\223\345\272\223\357\274\232 vlc-qt", Q_NULLPTR));
        label_6->setText(QApplication::translate("aboutDialog", "\347\274\226\350\257\221\345\231\250\357\274\232 GCC 5.3.1", Q_NULLPTR));
        label_7->setText(QApplication::translate("aboutDialog", "\345\256\214\346\210\220\346\227\245\346\234\237\357\274\232 ------------", Q_NULLPTR));
        label_8->setText(QApplication::translate("aboutDialog", "\346\235\216\344\270\200\351\270\243 \351\255\217\345\256\210\345\274\272 \346\235\216\344\275\263\350\261\252 \345\276\220\351\271\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class aboutDialog: public Ui_aboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
