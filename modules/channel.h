#ifndef CHANNEL_H
#define CHANNEL_H

#include <QStringList>

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

private:
    QString name;
    QString address;
};

#endif  //  CHANNEL_H
