#include "listdialog.h"
#include "ui_listdialog.h"

listDialog::listDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listDialog)
{
   ui->setupUi(this);
   setWindowFlags(Qt::FramelessWindowHint);
//   QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
   addWidget = new addDialog(this);
   ui->addButton->setFlat(true);
   ui->removeButton->setFlat(true);
   ui->uploadBtn->setEnabled(false);
//    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
//    setAttribute(Qt::WA_TranslucentBackground);

    mediaFormat << "mp3" << "wav" << "mp4" << "3gp" << "webm"
                << "mkv" << "avi";
    currentList = new GroupList();
    ChannelGroup *group = new ChannelGroup();
    group->setName("Default");
    currentList->addGroup(group);
    refreshList();

    loadSize = 4*1024;
    totalBytes = 0;
    bytesWritten = 0;
    bytesToWrite = 0;
    bytesReceived = 0;
    fileNameSize = 0;
    flagDown = false;
    recvPath = "/home/yeoman/";

    tcpClient = new QTcpSocket(this);

    connect(ui->treeWidget, &QTreeWidget::itemDoubleClicked, this, &listDialog::selectChannel);
    connect(ui->addButton, &QPushButton::clicked, addWidget, &addDialog::show);
    connect(ui->removeButton, &QPushButton::clicked, this, &listDialog::delGroupOrChannel);
    connect(ui->scanButton, &QPushButton::clicked, this, &listDialog::scanDirectory);

    connect(addWidget, &addDialog::addGroupOrChannel, this, &listDialog::addGroupOrChannel);
    connect(addWidget, &addDialog::addFromFile, this, &listDialog::addFromFile);

    connect(tcpClient, &QTcpSocket::connected, this, &listDialog::acceptConnection);
    connect(ui->connectBtn, &QPushButton::clicked, this, &listDialog::connectTOHost);
    connect(ui->openBtn, &QPushButton::clicked, this, &listDialog::openFile);
    connect(ui->uploadBtn, &QPushButton::clicked, this, &listDialog::send);
}

listDialog::~listDialog()
{
    delete currentList;
    delete addWidget;
    delete ui;
}

void listDialog::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos()+ mLastMousePosition);

}

void listDialog::mousePressEvent(QMouseEvent *event)
{
    mLastMousePosition =this->pos()-event->globalPos();
}

void listDialog::recordPos()
{
    record = this->pos();
}

void listDialog::moveDif(QPoint dif)
{
    this->move(record + dif);
}

void listDialog::connectTOHost()
{
    tcpClient->connectToHost(ui->hostLineEdit->text(), ui->portLineEdit->text().toInt());
//    tcpClient->connectToHost(QHostAddress::LocalHost, 6666);
}

void listDialog::acceptConnection()
{
//  refresh the progress
    connect(tcpClient, &QTcpSocket::readyRead, this, &listDialog::updateServerProgress);
    connect(tcpClient, &QTcpSocket::bytesWritten, this, &listDialog::updateClientProgress);
//    connect(tcpClient, &QTcpSocket::error, this, &listDialog::displayError);
    connect(tcpClient,SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
    ui->statusLabel->setText("connect test...");
    qDebug() << "connect success!";
}

void listDialog::openFile()
{
    fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty()) {
        ui->uploadBtn->setEnabled(true);
        ui->statusLabel->setText("打开文件成功");
    }
}

void listDialog::send()
{
    ui->uploadBtn->setEnabled(false);
    bytesWritten = 0;
    startTransfer();
}

void listDialog::startTransfer()
{
    if(!fileName.isEmpty()) {
        ui->uploadBtn->setEnabled(false);
        localFile = new QFile(fileName);
        if(!localFile->open(QFile::ReadOnly)) {
            qDebug() << "open file error";
            return;
        }
        totalBytes = localFile->size();
        QDataStream sendOut(&outBlock, QIODevice::WriteOnly);
        sendOut.setVersion(QDataStream::Qt_5_11);
        QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/') - 1);
        sendOut << qint64(0) << qint64(0) << currentFileName;
        totalBytes += outBlock.size();
        sendOut.device()->seek(0);
        sendOut << totalBytes << qint64((outBlock.size() - sizeof(qint64) * 2));
        bytesToWrite = totalBytes - tcpClient->write(outBlock);
        ui->statusLabel->setText("已连接");

    }
    else    qDebug() << "empty file";
//    outBlock.resize(0);
}

void listDialog::updateClientProgress(qint64 numBytes)
{
    if(flagDown == true)
    {
        flagDown = false;
        return ;
    }

    bytesWritten += (int)numBytes;
    if(bytesToWrite > 0)
    {
        outBlock = localFile->read(qMin(bytesToWrite,loadSize));
        bytesToWrite -= (int)tcpClient->write(outBlock);
        outBlock.resize(0);
    }else{
        localFile->close();
    }

    ui->clientProgressBar->setMaximum(totalBytes);
    ui->clientProgressBar->setValue(bytesWritten);
    if(bytesWritten == totalBytes)
    {
        ui->statusLabel->setText(tr("传送文件 %1 成功").arg(fileName));
        localFile->close();
        totalBytes = 0;
        bytesWritten = 0;
        bytesToWrite = 0;
        ui->clientProgressBar->setValue(0);
    }
}

void listDialog::updateServerProgress()
{
    QDataStream in(tcpClient);
    in.setVersion(QDataStream::Qt_5_11);

    if(bytesReceived <= sizeof(qint64)*2)
    {
        if((tcpClient->bytesAvailable() >=
            sizeof(qint64)*2) && (fileNameSize == 0))
        {
            in >> totalBytes >> fileNameSize;
            bytesReceived += sizeof(qint64) * 2;
        }
        if((tcpClient->bytesAvailable()
            >= fileNameSize) && (fileNameSize != 0))
            {
            in >> fileName;
            ui->statusLabel->setText(tr("接收文件 %1 …")
                                           .arg(fileName));
            bytesReceived += fileNameSize;
            localFile = new QFile(fileName);
            qDebug() << fileName;
//            localFile = new QFile(recvPath);
            if(!localFile->open(QFile::WriteOnly))
            {
                qDebug() << "open file error!";
                return;
            }
        } else
            return;
    }

    if(bytesReceived < totalBytes)
    {
        bytesReceived += tcpClient->bytesAvailable();
        inBlock = tcpClient->readAll();
        localFile->write(inBlock);
        inBlock.resize(0);
    }

    ui->clientProgressBar->setMaximum(totalBytes);
    ui->clientProgressBar->setValue(bytesReceived);
    if(bytesReceived == totalBytes)
    {
        localFile->close();
        //ui->sendButton->setEnabled(true);
        ui->statusLabel->setText(tr("接收文件 %1 成功！")
                                       .arg(fileName));
        bytesReceived = 0;
        fileNameSize = 0;
        totalBytes = 0;
    }
}

void listDialog::displayError(QAbstractSocket::SocketError)
{
    qDebug() << tcpClient->errorString();
    tcpClient->close();
    ui->clientProgressBar->reset();
    ui->statusLabel->setText(tr("客户端就绪"));
    ui->uploadBtn->setEnabled(true);
}

void listDialog::refreshList()
{
    ui->treeWidget->clear();
    for (int i = 0; i < currentList->count(); i++) {
        ChannelGroup *group = currentList->getGroup(i);
        QTreeWidgetItem *groupItem = new QTreeWidgetItem(QStringList()<<group->getName());
        ui->treeWidget->addTopLevelItem(groupItem);
        for (int j = 0; j < group->count(); j++) {
            Channel *channel = group->getChannel(j);
            QTreeWidgetItem *channelItem = new QTreeWidgetItem(QStringList()<<channel->getName());
            groupItem->addChild(channelItem);
        }
    }
}

void listDialog::selectChannel(QTreeWidgetItem *item, int index)
{
//    qDebug() << "selected" << endl;
    if (item->childCount())   return;
    QString name = item->text(index);
    for ( int i = 0; i < currentList->count(); ++i ) {
        ChannelGroup *group = currentList->getGroup(i);
        for ( int j = 0; j < group->count(); ++j ) {
            if (group->getChannel(j)->getName() == name)
                emit listPlay(group, j);
        }
    }
}

void listDialog::addGroupOrChannel(QString name, QString address)
{
    if (address.isEmpty()) {
        ChannelGroup *group = new ChannelGroup();
        group->setName(name);
        currentList->addGroup(group);

        refreshList();
    }
    else {
        Channel *channel = new Channel(name, address);
        QTreeWidgetItem *item = ui->treeWidget->currentItem();
        if (item == NULL) {
            ChannelGroup *group = currentList->getGroup(0);
            group->addChannel(channel);
        }
        else {
            if (item->parent())
                item = item->parent();
            QString groupName = item->text(0);
            ChannelGroup *group;
            for (int i = 0; i < currentList->count(); i++)
                if (currentList->getGroup(i)->getName() == groupName)
                    group = currentList->getGroup(i);
            group->addChannel(channel);
        }
    }
    refreshList();
}

void listDialog::delGroupOrChannel()
{
    QTreeWidgetItem *item = ui->treeWidget->currentItem();
    if (item->parent()) {
        ChannelGroup *group;
        QString groupName = item->parent()->text(0);
        for (int i = 0; i < currentList->count(); ++i)
            if (currentList->getGroup(i)->getName() == groupName)
                group = currentList->getGroup(i);
        for (int j = 0; j < group->count(); ++j )
            if (group->getChannel(j)->getName() == item->text(0))
                group->delChannel(j);
        refreshList();
    }
    else {
        if (item->text(0) == currentList->getGroup(0)->getName())
            QMessageBox::warning(this, "注意", "默认组不能进行删除操作！", QMessageBox::Ok);
        else {
            QString groupName = item->text(0);
            for (int i = 0; i < currentList->count(); ++i)
                if (currentList->getGroup(i)->getName() == groupName)
                    currentList->delGroup(i);
            refreshList();
        }
    }
    qDebug() << "delete" << endl;
}

void listDialog::addFromFile(QStringList fileList, QString groupName)
{
    ChannelGroup * group;
    if (!groupName.isEmpty())
        addGroupOrChannel(groupName, "");
    QString tempStr;
    QTreeWidgetItem * item = ui->treeWidget->currentItem();
    if (NULL == item)   tempStr = currentList->getGroup(0)->getName();
    else {
        item = item->parent()? item->parent() : item;
        tempStr = item->text(0);
    }
    groupName = groupName.isEmpty()? tempStr : groupName;
    for (int i = 0; i < currentList->count(); ++i)
        if (currentList->getGroup(i)->getName() == groupName)
            group = currentList->getGroup(i);
    for (int i = 0; i < fileList.length(); ++i) {
        QString fileName = fileList.at(i);
        int temp = fileName.lastIndexOf('/');
        fileName = fileName.mid(temp + 1);
        temp = fileName.lastIndexOf('.');
        fileName.truncate(temp);
        Channel *channel = new Channel(fileName, fileList.at(i));
        group->addChannel(channel);
    }
    refreshList();
}

void listDialog::scanFiles(const char *dirPath, QStringList & fileList)
{
    struct dirent * ent = NULL;
    DIR * pDir;
    pDir = opendir(dirPath);
    if (NULL == pDir)	return;
    while (NULL != (ent = readdir(pDir))) {
        std :: string _path(dirPath);
        std :: string fullPath = _path + "/";
        std :: string thisName(ent -> d_name);
        fullPath += thisName;
        if (8 == ent -> d_type) {
            QString qsfullpath = QString :: fromStdString(fullPath);
            int temp = qsfullpath.lastIndexOf('.');
            QString thisFormat = qsfullpath.mid(temp + 1);
            if (mediaFormat.end() != mediaFormat.find(thisFormat))
                fileList.append(qsfullpath);
        }
        else {
            if (strcmp(ent -> d_name, ".") == 0 || strcmp(ent -> d_name, "..") == 0)
                continue;
            scanFiles(fullPath.c_str(), fileList);
        }
    }
}

void listDialog::scanDirectory()
{
    QString qstr = QFileDialog::getExistingDirectory(this, "选择目录",
                                                    "/home/yeoman",
                                                    QFileDialog::ShowDirsOnly);
    std :: string str = qstr.toStdString();
    const char * dirPath = str.c_str();
    QStringList fileList;
    scanFiles(dirPath, fileList);
    int temp = qstr.lastIndexOf('/');
    qstr = qstr.mid(temp + 1);
    addFromFile(fileList, qstr);
}
