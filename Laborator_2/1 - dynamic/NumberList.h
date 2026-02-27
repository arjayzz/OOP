#pragma once
struct nod
{
    int info;
    nod* urm;
};
class NumberList
{//private
    nod* head;
    int count;
public:
    void Init();          // count will be 0
    bool Add(int x);      // adds X to the numbers list and increase the data member count.

    void Sort();          // will sort the numbers vector
    void Print();         // will print the current vector

    ~NumberList();
   
};
