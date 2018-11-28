/********************************************************************************
** Form generated from reading UI file 'adddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDIALOG_H
#define UI_ADDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_addDialog
{
public:
    QGroupBox *combBox;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *titleLine;
    QLineEdit *addressLine;
    QPushButton *fileButton;
    QRadioButton *groupButton;
    QLineEdit *groupLine;
    QPushButton *yesButton;
    QPushButton *noButton;
    QRadioButton *stationButton;

    void setupUi(QDialog *addDialog)
    {
        if (addDialog->objectName().isEmpty())
            addDialog->setObjectName(QStringLiteral("addDialog"));
        addDialog->resize(335, 195);
        addDialog->setMinimumSize(QSize(335, 195));
        addDialog->setMaximumSize(QSize(335, 195));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        addDialog->setFont(font);
        combBox = new QGroupBox(addDialog);
        combBox->setObjectName(QStringLiteral("combBox"));
        combBox->setEnabled(true);
        combBox->setGeometry(QRect(30, 50, 291, 101));
        combBox->setFlat(false);
        combBox->setCheckable(false);
        label = new QLabel(combBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(5, 30, 75, 19));
        label_3 = new QLabel(combBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(5, 60, 75, 19));
        titleLine = new QLineEdit(combBox);
        titleLine->setObjectName(QStringLiteral("titleLine"));
        titleLine->setEnabled(true);
        titleLine->setGeometry(QRect(92, 27, 150, 23));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        titleLine->setFont(font1);
        addressLine = new QLineEdit(combBox);
        addressLine->setObjectName(QStringLiteral("addressLine"));
        addressLine->setGeometry(QRect(92, 57, 191, 23));
        addressLine->setFont(font1);
        fileButton = new QPushButton(combBox);
        fileButton->setObjectName(QStringLiteral("fileButton"));
        fileButton->setGeometry(QRect(0, 80, 101, 21));
        groupButton = new QRadioButton(addDialog);
        groupButton->setObjectName(QStringLiteral("groupButton"));
        groupButton->setGeometry(QRect(15, 15, 70, 25));
        groupLine = new QLineEdit(addDialog);
        groupLine->setObjectName(QStringLiteral("groupLine"));
        groupLine->setEnabled(false);
        groupLine->setGeometry(QRect(95, 15, 131, 23));
        groupLine->setFont(font1);
        yesButton = new QPushButton(addDialog);
        yesButton->setObjectName(QStringLiteral("yesButton"));
        yesButton->setGeometry(QRect(81, 155, 80, 27));
        noButton = new QPushButton(addDialog);
        noButton->setObjectName(QStringLiteral("noButton"));
        noButton->setGeometry(QRect(181, 155, 80, 27));
        stationButton = new QRadioButton(addDialog);
        stationButton->setObjectName(QStringLiteral("stationButton"));
        stationButton->setEnabled(true);
        stationButton->setGeometry(QRect(15, 50, 85, 25));
        stationButton->setChecked(true);
        QWidget::setTabOrder(groupButton, groupLine);
        QWidget::setTabOrder(groupLine, stationButton);
        QWidget::setTabOrder(stationButton, titleLine);
        QWidget::setTabOrder(titleLine, addressLine);
        QWidget::setTabOrder(addressLine, yesButton);
        QWidget::setTabOrder(yesButton, noButton);

        retranslateUi(addDialog);

        QMetaObject::connectSlotsByName(addDialog);
    } // setupUi

    void retranslateUi(QDialog *addDialog)
    {
        addDialog->setWindowTitle(QApplication::translate("addDialog", "\346\267\273\345\212\240", Q_NULLPTR));
        combBox->setTitle(QString());
        label->setText(QApplication::translate("addDialog", "\351\242\221\351\201\223\346\240\207\351\242\230\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("addDialog", "\351\242\221\351\201\223\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        titleLine->setText(QString());
        addressLine->setText(QString());
        fileButton->setText(QApplication::translate("addDialog", "\346\226\207\344\273\266", Q_NULLPTR));
        groupButton->setText(QApplication::translate("addDialog", "\346\267\273\345\212\240\347\273\204", Q_NULLPTR));
        groupLine->setText(QString());
        yesButton->setText(QApplication::translate("addDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        noButton->setText(QApplication::translate("addDialog", "\345\217\226\346\266\210", Q_NULLPTR));
        stationButton->setText(QApplication::translate("addDialog", "\346\267\273\345\212\240\351\242\221\351\201\223", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class addDialog: public Ui_addDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDIALOG_H
