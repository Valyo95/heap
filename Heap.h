//
// Created by valyo95 on 26/11/2017.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H

#include <stdio.h>
#include <iostream>
#include "HeapNode.h"

#define INIT_DEPTH 1

namespace project {

class Heap {
private:
    int depth_;
    int capacity_;
    int size_;

    HeapNode** heap_;
public:
    Heap();

    virtual ~Heap();

    void Reset();

    int Left(int parent);
    int Right(int parent);
    int Parent(int child);

    void ExtendHeap();
    void Insert(String* index);
    void Insert(String *str, int times, int index);
    void Swap(int a, int b);
    void InsertFit(HeapNode* index);

    void BubbleUp(int index);
    void BubbleDown(int index);
    int MaxChild(int index);
    HeapNode *PopMax();

    void PrintTopK(int k);

    int IsIn(String *str);
    void Update(int index);
    void Print();

};

}

#endif //HEAP_HEAP_H
