#include <iostream>
#include "Heap.h"
#include "String.h"
int main()
{


    project::Heap *h = new project::Heap();

    project::String *s = new project::String();
    s->Insert("dada");

    project::String *s1 = new project::String();
    s1->Insert("aaa");

    project::String *s2 = new project::String();
    s2->Insert("nene ");

    project::String *s3 = new project::String();
    s3->Insert("easccc");

    project::String *s4 = new project::String();
    s4->Insert("badasd");

    h->Print();

    h->Insert(s);
    h->Insert(s1);
    h->Insert(s2);
    h->Insert(s3);
    h->Insert(s4);

    h->Print();

    h->PrintTopK(3);
/*
    h->Insert(s);
    h->Insert(s2);
    h->Insert(s3);
    h->Insert(s3);
*/

    delete h->PopMax();
    h->Print();

    delete s;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete h;


}