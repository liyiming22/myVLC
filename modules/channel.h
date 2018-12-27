#ifndef CHANNEL_H
#define CHANNEL_H

#include <QStringList>
#include <QDebug>

class Channel
{
public:
    Channel();
    Channel(QString name, QString address);

    void setChannel(QString channel);
    void setName(QString name);
    void setAddress(QString address);

    QString getChannel();
    QString getName();
    QString getAddress();
    QString getFormat();

private:
    QString name;
    QString address;
    QString format;
};

#endif  //  CHANNEL_H
