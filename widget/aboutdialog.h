#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

/***********************************************************
 * 关于窗口
 ***********************************************************/

#include <QDialog>
#include <QCloseEvent>

namespace Ui {
class aboutDialog;
}

class aboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit aboutDialog(QWidget *parent = 0);
    ~aboutDialog();

    void closeEvent(QCloseEvent *);

private:
    Ui::aboutDialog *ui;
};

#endif // ABOUTDIALOG_H
