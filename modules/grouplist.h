#ifndef GROUPLIST_H
#define GROUPLIST_H

#include "channelgroup.h"

class GroupList
{
public:
    GroupList();

    void addGroup(ChannelGroup *);
    void delGroup(int);
    ChannelGroup *getGroup(int);
    int count();

private:
    QList<ChannelGroup *> list;
};

#endif  //  GROUPLIST_H
