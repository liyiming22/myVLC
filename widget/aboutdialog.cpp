#include "aboutdialog.h"
#include "ui_aboutdialog.h"

aboutDialog::aboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutDialog)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QAbstractButton::clicked, this, &QWidget::hide);
}

aboutDialog::~aboutDialog()
{
    delete ui;
}

void aboutDialog::closeEvent(QCloseEvent *event)
{
    event->ignore();
    this->hide();
}
