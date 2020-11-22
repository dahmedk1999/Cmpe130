//
// Created by Danish Khan on 11/22/2020.
//

#ifndef CMPE130_DISJOINT_H
#define CMPE130_DISJOINT_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class disjointSet {
public :
    disjointSet();

    disjointSet(int size);

    ~disjointSet();

    void union_function(int firstVal, int secondVal);

    int searchSet(int index);

    bool sameComponent(int firstA, int secondB);

    int getNumSets() const {
        return setnum;
    }

    void prints_the_sets();

private :
    void linker(int firstVal, int secondVal);

    void createsSet(int firstVal);

    int totsize;
    int setnum;
    int *tracker_maze;
    int *main_maze;
};

#endif //CMPE130_DISJOINT_H
