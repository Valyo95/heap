//
// Created by valyo95 on 26/11/2017.
//

#include <cstring>
#include "Heap.h"
namespace project {

    Heap::Heap() : depth_(INIT_DEPTH), capacity_((2 << depth_) - 1), size_(0), heap_(nullptr) {
        heap_ = static_cast<HeapNode**>(malloc(sizeof(HeapNode*) * capacity_));
        for (int i = 0; i < capacity_; ++i) {
            heap_[i] = nullptr;
        }
    }

    Heap::~Heap(){
        for (int i = 0; i < capacity_; ++i) {
            if(heap_[i] != nullptr) {
                delete heap_[i];
            }
        }
        free(heap_);
    }

    void Heap::Reset() {
        depth_ = INIT_DEPTH;
        capacity_ = (2 << depth_) -1;
        size_ = 0;
        delete[] heap_;
        heap_ = static_cast<HeapNode**>(malloc(sizeof(HeapNode*) * capacity_));
    }

    int Heap::Left(int parent){
        int i = ( parent * 2 ) + 1; // 2 * parent + 1
        return ( i < size_ ) ? i : -1;
    }

    int Heap::Right(int parent){
        int i = ( parent * 2 ) + 2; // 2 * parent + 2
        return ( i < size_ ) ? i : -1;
    }

    int Heap::Parent(int child){
        if (child != 0)
        {
            int i = (child - 1) >> 1;
            return i;
        }
        return -1;
    }

    void Heap::Swap(int a, int b) {
        HeapNode *tmp = heap_[a];
        heap_[a] = heap_[b];
        heap_[b] = tmp;
    }

    void Heap::ExtendHeap() {
        depth_++;
        int newCapacity = (2 <<depth_) -1;
        HeapNode **newHeap = static_cast<HeapNode **>(malloc(sizeof(HeapNode *) * newCapacity));
        memmove(newHeap, heap_, capacity_*sizeof(*heap_));
        free(heap_);

        heap_ = newHeap;
        capacity_ = newCapacity;
        for (int i = size_; i < capacity_; ++i) {
            heap_[i] = nullptr;
        }
    }

    void Heap::InsertFit(HeapNode* index) {
    //    printf("Inserting string: %s\n", index->getString_());

        size_++;
        heap_[size_-1] = index;
        BubbleUp(size_-1);
    }

    void Heap::BubbleUp(int index) {
        while(Parent(index) != -1 && (*heap_[index] > *heap_[Parent(index)])){
            Swap(index, Parent(index));
            index = Parent(index);
        }
    }

    void Heap::BubbleDown(int index) {
    //    printf("BubbleDown\n");
        while(MaxChild(index) >= 0 && MaxChild(index) < size_ && (*heap_[index] < *heap_[MaxChild(index)])) {
            Print();
            Swap(index, MaxChild(index));
            index = MaxChild(index);
        }
    }

    HeapNode *Heap::PopMax()
    {
        HeapNode *max = heap_[0];
        heap_[0] = heap_[size_-1];
        heap_[size_-1] = nullptr;
        size_--;
        BubbleDown(0);

        return max;
    }

    void Heap::PrintTopK(int k)
    {
        printf("Top %d\n", k);
        int index = 0;
        int left, right;
        HeapNode *tmp;
        project::Heap *h = new project::Heap();

        h->Insert(heap_[0]->getString_(), heap_[0]->getTimes_(), 0);

        for (int i = 0; i < k; ++i) {
/*
            printf("Before pop\n");
            h->Print();
*/
            tmp = h->PopMax();
/*
            printf("After pop\n");
            h->Print();
*/

            index = tmp->getIndex_();
            tmp->print();
            delete tmp;

            left = Left(index);
            right = Right(index);

/*
            printf("index: %d\n", index);
            printf("left: %d\n", left);
            printf("right: %d\n", right);
*/

            if(left == -1)
                continue;
            else{
                h->Insert(heap_[left]->getString_(), heap_[left]->getTimes_(), left);
                if(right == -1)
                    continue;
                h->Insert(heap_[right]->getString_(), heap_[right]->getTimes_(), right);
            }
        }
        delete h;

    }

    int Heap::MaxChild(int index) {
        int rightIndex = Right(index);
        int leftIndex = Left(index);

        if(leftIndex == -1)
            return -1;

        if(rightIndex == -1)
            return leftIndex;
        else
        {
            HeapNode *right = heap_[rightIndex];
            HeapNode *left = heap_[Left(index)];

            if(*left > *right)
                return Left(index);
            else
                return Right(index);
        }

    }

    int Heap::IsIn(String *str) {
        for (int i = 0; i < size_; ++i) {
            if(*str == *(heap_[i]->getString_()))
                return i;
        }
        return -1;
    }

    void Heap::Insert(String* index) {
        int isIn = IsIn(index);
        if(isIn == -1) {
            HeapNode *heapNode = new HeapNode(1, index);
            if(size_ + 1 <= capacity_) {
                InsertFit(heapNode);
            } else {                // gotta extend the heap
                ExtendHeap();
                InsertFit(heapNode);
            }
        }
        else {
            Update(isIn);
        }
    //    Print();
    }

    void Heap::Insert(String *str, int times, int index)
    {
        int isIn = IsIn(str);
        if(isIn == -1) {
            HeapNode *heapNode = new HeapNode(times, str, index);
            if(size_ + 1 <= capacity_) {
                InsertFit(heapNode);
            } else {                // gotta extend the heap
                ExtendHeap();
                InsertFit(heapNode);
            }
        }
        else {
            Update(isIn);
        }
        //    Print();
    }



    void Heap::Update(int index){
    //    printf("Updating string: %s\n", heap_[index]->getString_());
        heap_[index]->setTimes_(heap_[index]->getTimes_()+1);
        BubbleUp(index);
    }

    void Heap::Print() {
        printf("---Heap---\nDepth: %d\nCapacity: %d\nSize: %d\n\n", depth_, capacity_, size_);
        for (int i = 0; i < size_; ++i) {
            printf("heap[%d] = ", i);
            heap_[i]->print();
        }
        printf("\n");

    }
}