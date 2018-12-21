#ifndef LISTDIALOG_H
#define LISTDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QTreeWidgetItem>
#include <QFileDialog>
#include <QTextCodec>
#include <QSet>
#include <QMouseEvent>
#include <QtNetwork>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

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
    void scanFiles(const char * dirPath, QStringList & fileList);
    QSet<QString> mediaFormat;

protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);

signals:
//    void listPlay(QString, QString);
    void listPlay(ChannelGroup *, int);

public slots:
    void recordPos();
    void moveDif(QPoint);

    void selectChannel(QTreeWidgetItem *, int);
    void addGroupOrChannel(QString, QString);
//    void addFromFile(QStringList);
    void addFromFile(QStringList, QString);
    void delGroupOrChannel();
    void scanDirectory();

//    服务器客户端相关
    void acceptConnection();
    void send(); //连接服务器
    void startTransfer(); //发送文件大小等信息
    void updateClientProgress(qint64); //发送数据，更新进度条
    void updateServerProgress(); //更新进度条，接收数据
    void displayError(QAbstractSocket::SocketError); //显示错误
    void openFile(); //打开文件

private:
    Ui::listDialog *ui;
    QPoint record;
    QPoint mLastMousePosition;
    GroupList *currentList;
    addDialog *addWidget;

    //    服务器客户端相关
    QTcpSocket *tcpClient;
    QFile *localFile; //要发送的文件
    qint64 totalBytes; //数据总大小
    qint64 bytesWritten; //已经发送数据大小
    qint64 bytesToWrite; //剩余数据大小
    qint64 loadSize; //每次发送数据的大小
    QString fileName; //保存文件路径
    QByteArray outBlock; //数据缓冲区，即存放每次要发送的数据


    qint64 bytesReceived; //已收到数据的大小
    qint64 fileNameSize; //文件名的大小信息
    QByteArray inBlock; //数据缓冲区

    QString recvPath;

    bool flagDown;
};

#endif // LISTDIALOG_H
