#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork>
#include <QString>

namespace Ui {
    class Widget;
}

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Widget *ui;
    QTcpServer tcpServer;
    QTcpSocket *tcpServerConnection;
    qint64 totalBytes; //存放总大小信息
    qint64 bytesReceived; //已收到数据的大小
    qint64 fileNameSize; //文件名的大小信息
    QString fileName; //存放文件名
    QFile *localFile; //本地文件
    QByteArray inBlock; //数据缓冲区
    
    QString wfileName;
    qint64 bytesWritten; //已经发送数据大小
    qint64 bytesToWrite; //剩余数据大小
    qint64 loadSize; //每次发送数据的大小
    QByteArray outBlock; //数据缓冲区，即存放每次要发送的数据

    bool flagDown;      //下载

private slots:
    void on_sendpushButton_clicked();
    void on_addFileButton_clicked();
    void on_startButton_clicked();
    void start(); //开始监听
    void acceptConnection(); //建立连接
    void updateServerProgress(); //更新进度条，接收数据
    void displayError(QAbstractSocket::SocketError socketError);

    void updateClientProgress(qint64); //发送数据，更新进度条
};

#endif // WIDGET_H
