//
// Created by valyo95 on 26/11/2017.
//

#include <cstring>
#include <cstdio>
#include "HeapNode.h"

project::HeapNode::HeapNode(int times_, project::String *string_) : times_(times_), string_(string_) {}

void project::HeapNode::print()
{
    printf("String: %s, index: %d\n", string_, times_);
}

bool project::HeapNode::operator==(const project::HeapNode &rhs) const
{
    printf("hahahha\n");
    return times_ == rhs.times_ &&
           *string_ == *rhs.string_;
}

bool project::HeapNode::operator!=(const project::HeapNode &rhs) const
{
    return !(rhs == *this);
}

bool project::HeapNode::operator<(const project::HeapNode &rhs) const
{
    if(times_ < rhs.times_)
        return true;
    if(rhs.times_ < times_)
        return false;
    return *string_ < *rhs.string_;
}

bool project::HeapNode::operator>(const project::HeapNode &rhs) const
{
    return rhs < *this;
}

bool project::HeapNode::operator<=(const project::HeapNode &rhs) const
{
    return !(rhs < *this);
}

bool project::HeapNode::operator>=(const project::HeapNode &rhs) const
{
    return !(*this < rhs);
}

int project::HeapNode::getTimes_() const
{
    return times_;
}

void project::HeapNode::setTimes_(int times_)
{
    HeapNode::times_ = times_;
}

void project::HeapNode::setString_(project::String *string_)
{
    HeapNode::string_ = string_;
}

project::String *project::HeapNode::getString_() const
{
    return string_;
}

int project::HeapNode::getIndex_() const
{
    return index_;
}

project::HeapNode::HeapNode(int times_, project::String *string_, int index_) : times_(times_), string_(string_),
                                                                                index_(index_) {}

void project::HeapNode::setIndex_(int index_)
{
    HeapNode::index_ = index_;
}


