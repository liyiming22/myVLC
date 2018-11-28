#ifndef ADDDIALOG_H
#define ADDDIALOG_H

/*********************************************************************
 * 增加频道/组窗口
 **********************************************************************/

#include <QDialog>
#include <QMessageBox>
#include <modules/channelgroup.h>
#include <QDebug>
#include <QFileDialog>

namespace Ui {
class addDialog;
}

class addDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addDialog(QWidget *parent = 0);
    ~addDialog();

private:
    Ui::addDialog *ui;

signals:
    void addGroupOrChannel(QString, QString);
    void addFromFile(QStringList);

private slots:
    void stationInvalid();
    void groupInvalid();

    void enter();
    void cancel();
    void importFromFile();
};

#endif // ADDDIALOG_H
