#include "listdialog.h"
#include "ui_listdialog.h"

listDialog::listDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listDialog)
{
    ui->setupUi(this);
//    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
//    setAttribute(Qt::WA_TranslucentBackground);

    currentList = new GroupList();
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));

    ChannelGroup *group = new ChannelGroup();
    group->setName("Default");
    currentList->addGroup(group);
    refreshList();

    addWidget = new addDialog(this);

    connect(ui->treeWidget, &QTreeWidget::itemDoubleClicked, this, &listDialog::selectChannel);
    connect(ui->addButton, &QPushButton::clicked, addWidget, &addDialog::show);
    connect(ui->removeButton, &QPushButton::clicked, this, &listDialog::delGroupOrChannel);
    connect(ui->debugButton, &QPushButton::clicked, this, &listDialog::debug);

    connect(addWidget, &addDialog::addGroupOrChannel, this, &listDialog::addGroupOrChannel);
    connect(addWidget, &addDialog::addFromFile, this, &listDialog::addFromFile);
}

listDialog::~listDialog()
{
    delete currentList;
    delete addWidget;
    delete ui;
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

void listDialog::recordPos()
{
    record = this->pos();
}

void listDialog::moveDif(QPoint dif)
{
    this->move(record + dif);
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

void listDialog::addFromFile(QStringList fileList)
{
    QTreeWidgetItem * item = ui->treeWidget->currentItem();
    ChannelGroup * group;
    if (item == NULL)   group = currentList->getGroup(0);
    else {
        if (item->parent()) item = item->parent();
        QString groupName = item->text(0);
        for (int i = 0; i < currentList->count(); ++i)
            if (currentList->getGroup(i)->getName() == groupName)
                group = currentList->getGroup(i);
    }
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

void listDialog::dfsFiles(const char *dirPath, QStringList & fileList)
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
            // file
            QString qsfullpath = QString :: fromStdString(fullPath);
//            qDebug() << qsfullpath;
            fileList.append(qsfullpath);
        }
        else {
            if (strcmp(ent -> d_name, ".") == 0 || strcmp(ent -> d_name, "..") == 0)
                continue;
            // directory
            dfsFiles(fullPath.c_str(), fileList);
        }
    }
}

void listDialog::debug()
{
    QString qstr = QFileDialog::getExistingDirectory(this, "选择目录",
                                                    "/home/yeoman",
                                                    QFileDialog::ShowDirsOnly);
    std :: string str = qstr.toStdString();
    const char * dirPath = str.c_str();
//    QByteArray ba = qstr.toLocal8Bit();
//    char * dirPath = ba.data();
    QStringList fileList;
    dfsFiles(dirPath, fileList);
}
