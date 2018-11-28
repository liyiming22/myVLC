#ifndef LISTDIALOG_H
#define LISTDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QTreeWidgetItem>
#include "modules/grouplist.h"
#include "widget/adddialog.h"

namespace Ui {
class listDialog;
}

class listDialog : public QDialog
{
    Q_OBJECT

public:
    explicit listDialog(QWidget *parent = 0);
    ~listDialog();
    void refreshList();

signals:
//    void listPlay(QString, QString);
    void listPlay(ChannelGroup *, int);

public slots:
    void recordPos();
    void moveDif(QPoint);

    void selectChannel(QTreeWidgetItem *, int);
    void addGroupOrChannel(QString, QString);
    void addFromFile(QStringList);
    void delGroupOrChannel();

private:
    Ui::listDialog *ui;
    QPoint record;

    GroupList *currentList;

    addDialog *addWidget;
};

#endif // LISTDIALOG_H
