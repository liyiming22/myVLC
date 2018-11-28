/********************************************************************************
** Form generated from reading UI file 'listdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTDIALOG_H
#define UI_LISTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_listDialog
{
public:
    QTreeWidget *treeWidget;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *debugButton;

    void setupUi(QDialog *listDialog)
    {
        if (listDialog->objectName().isEmpty())
            listDialog->setObjectName(QStringLiteral("listDialog"));
        listDialog->resize(231, 362);
        treeWidget = new QTreeWidget(listDialog);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(0, 20, 231, 281));
        addButton = new QPushButton(listDialog);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(0, 320, 31, 27));
        removeButton = new QPushButton(listDialog);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setGeometry(QRect(40, 320, 31, 27));
        debugButton = new QPushButton(listDialog);
        debugButton->setObjectName(QStringLiteral("debugButton"));
        debugButton->setGeometry(QRect(190, 320, 31, 27));

        retranslateUi(listDialog);

        QMetaObject::connectSlotsByName(listDialog);
    } // setupUi

    void retranslateUi(QDialog *listDialog)
    {
        listDialog->setWindowTitle(QApplication::translate("listDialog", "\346\222\255\346\224\276\345\210\227\350\241\250", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("listDialog", "\345\210\227\350\241\250", Q_NULLPTR));
        addButton->setText(QApplication::translate("listDialog", "+", Q_NULLPTR));
        removeButton->setText(QApplication::translate("listDialog", "-", Q_NULLPTR));
        debugButton->setText(QApplication::translate("listDialog", "bug", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class listDialog: public Ui_listDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTDIALOG_H
