#ifndef CHANNELGROUP_H
#define CHANNELGROUP_H

#include "channel.h"

class ChannelGroup
{
public:
    ChannelGroup();

    QString getName();
    void setName(QString);

    void addChannel(Channel *);
    void delChannel(int);
    Channel *getChannel(int);
    int count();

private:
    QString groupName;
    QList<Channel *> group;
};

#endif  //  CHANNELGROUP_H
