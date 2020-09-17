//
// Created by Danish Khan on 9/15/2020.
//
#ifndef CMPE130_TREE_H
#define CMPE130_TREE_H
#include <iostream>
#include <cstdio>
using namespace std;

class tree {//dummy tree
public:
    int * value;
    tree * left;
    tree * right;

    bool Maxheap(int A[],int size);
    bool minheap(int A[],int size);


};


#endif //CMPE130_TREE_H
