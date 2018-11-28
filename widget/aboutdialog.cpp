#include "aboutdialog.h"
#include "ui_aboutdialog.h"

aboutDialog::aboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutDialog)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(hide()));
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
