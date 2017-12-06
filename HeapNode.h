//
// Created by valyo95 on 26/11/2017.
//

#ifndef HEAP_HEAPNODE_H
#define HEAP_HEAPNODE_H

#include "String.h"
namespace project {

class HeapNode {
private:
    int times_;
    String *string_;

    int index_;

public:
    HeapNode(const String &string);

    HeapNode(int times_, String *string_);

    HeapNode(int times_, String *string_, int index_);

    int getIndex_() const;

    void setIndex_(int index_);

    int getTimes_() const;

    String *getString_() const;

    bool operator<(const HeapNode &rhs) const;

    bool operator>(const HeapNode &rhs) const;

    bool operator<=(const HeapNode &rhs) const;

    bool operator>=(const HeapNode &rhs) const;

    bool operator==(const HeapNode &rhs) const;

    bool operator!=(const HeapNode &rhs) const;

    void print();

    void setTimes_(int times_);

    void setString_(String *string_);
};

}

#endif //HEAP_HEAPNODE_H
