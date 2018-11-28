#include "channelgroup.h"


ChannelGroup::ChannelGroup()
{

}

QString ChannelGroup::getName()
{
    return groupName;
}

void ChannelGroup::setName(QString name)
{
    this->groupName = name;
}

void ChannelGroup::addChannel(Channel *channel)
{
    group.append(channel);
}

void ChannelGroup::delChannel(int index)
{
    group.removeAt(index);
}

Channel *ChannelGroup::getChannel(int index)
{
    return group.at(index);
}

int ChannelGroup::count()
{
    return group.count();
}
