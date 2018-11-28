#include "channel.h"

Channel::Channel(QString name, QString address)
{
    this->name = name;
    this->address = address;
}

void Channel::setChannel(QString channel)
{
    this->name = channel.split("#").at(0);
    this->address = channel.split("#").at(1);
}

void Channel::setName(QString name)
{
    this->name = name;
}

void Channel::setAddress(QString address)
{
    this->address = address;
}

QString Channel::getChannel()
{
    QString channel = this->name + "#" + this->address;
    return channel;
}

QString Channel::getName()
{
    return name;
}

QString Channel::getAddress()
{
    return address;
}
