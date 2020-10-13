//
// Created by Danish Khan on 9/15/2020.
//
#ifndef CMPE130_FAKETREE_H
#define CMPE130_FAKETREE_H
#include <iostream>
#include <cstdio>
using namespace std;

class faketree {//dummy faketree
public:
    int * value;
    faketree * left;
    faketree * right;

    bool Maxheap(int A[],int size);
    bool minheap(int A[],int size);


};


#endif //CMPE130_FAKETREE_H
