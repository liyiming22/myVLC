#include "grouplist.h"

GroupList::GroupList()
{

}

void GroupList::addGroup(ChannelGroup *group)
{
    list.append(group);
}

void GroupList::delGroup(int index)
{
    list.removeAt(index);
}

ChannelGroup *GroupList::getGroup(int index )
{
    return list.at(index);
}

int GroupList::count()
{
    return list.count();
}
