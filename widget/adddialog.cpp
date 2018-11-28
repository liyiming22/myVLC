#include "adddialog.h"
#include "ui_adddialog.h"

addDialog::addDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDialog)
{
    ui->setupUi(this);

    connect(ui->groupButton, &QAbstractButton::pressed, this, &addDialog::stationInvalid);
    connect(ui->stationButton, &QAbstractButton::pressed, this, &addDialog::groupInvalid);
    connect(ui->yesButton, &QAbstractButton::clicked, this, &addDialog::enter);
    connect(ui->noButton, &QAbstractButton::clicked, this, &addDialog::cancel);
    connect(ui->fileButton, &QPushButton::clicked, this, &addDialog::importFromFile);
}

addDialog::~addDialog()
{
    delete ui;
}

void addDialog::stationInvalid()
{
    ui->combBox->setEnabled(false);

    ui->groupLine->setEnabled(true);
}

void addDialog::groupInvalid()
{
    ui->groupLine->setEnabled(false);

    ui->combBox->setEnabled(true);
}

void addDialog::enter()
{
    if (ui->groupButton->isChecked())
    {
        QString groupName = ui->groupLine->text();
        if (!groupName.isEmpty())
        {
            emit addGroupOrChannel(groupName, "");
            cancel();
        }
        else
            QMessageBox::warning(this, "注意", "请输入完整信息！", QMessageBox::Ok);
    }
    else
    {
        QString channelName = ui->titleLine->text();
        QString channelAddress = ui->addressLine->text();

        if (channelName.isEmpty() || channelAddress.isEmpty())
            QMessageBox::warning(this, "注意", "请输入完整信息！", QMessageBox::Ok);
        else
        {
            emit addGroupOrChannel(channelName, channelAddress);
            cancel();
        }
    }
}

void addDialog::cancel()
{
    ui->stationButton->setChecked(true);
    ui->combBox->setEnabled(true);
    ui->titleLine->clear();
    ui->addressLine->clear();

    ui->groupLine->setEnabled(false);
    ui->groupLine->clear();

    this->close();
}

void addDialog::importFromFile()
{
    QStringList fileList =
            QFileDialog :: getOpenFileNames(this, "Open file",
                                         "/home/yeoman",
                                         "Multimedia files(*)");
    if (0 == fileList.length()) return;
    emit addFromFile(fileList);
    this->close();
}
