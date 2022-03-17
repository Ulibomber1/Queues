#include <iostream>
#include "Vector.h"
#include "Queue.h"
using namespace std;

int main()
{
    Vector<Vector<int>* > tree;

    for (int i = 0; i <= 12; i++)
        tree.push_back(nullptr);

    Vector<int> sub1;
    sub1.push_back(2);
    sub1.push_back(7);

    Vector<int> sub2;
    sub2.push_back(3);
    sub2.push_back(4);

    Vector<int> sub4;
    sub4.push_back(5);
    sub4.push_back(6);

    Vector<int> sub7;
    sub7.push_back(8);
    sub7.push_back(9);

    Vector<int> sub8;
    sub8.push_back(10);

    Vector<int> sub10;
    sub2.push_back(11);
    sub2.push_back(12);


    tree[1] = &sub1;
    tree[2] = &sub2;
    tree[4] = &sub4;
    tree[7] = &sub7;
    tree[8] = &sub8;
    tree[10] = &sub10;


    Queue<List<int> > myq;
    myq.enqueue(1);
    while (!myq.empty())
    {
        int next = myq.front();
        myq.dequeue();

        Vector<int>* sub = tree[next];
        if (sub != nullptr)
            for (int i = 0; i < sub->size(); i++)
                myq.enqueue((&sub[i]));
    }


}
