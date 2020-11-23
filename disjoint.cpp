//
// Created by Danish Khan on 11/22/2020.
//

#include "disjoint.h"

disjointSet::disjointSet() {
//empty
}

disjointSet::disjointSet(int size) {
    if(!size)exit(1);
    setnum = size;
    totsize = size;
    child_maze = new int[size];
    main_maze = new int[size];
    for (int i = 0; i < size; ++i) {
        createsSet(i);
    }

}

disjointSet::~disjointSet() {
    delete[] child_maze;
    delete[] main_maze;
}

void disjointSet::union_function(int firstVal, int secondVal) {
    if (firstVal < 0 || firstVal >= totsize || secondVal < 0 || secondVal >= totsize) return;
    linker(searchSet(firstVal), searchSet(secondVal));
}

int disjointSet::searchSet(int index) {
    if (index < 0 || index >= totsize)
        return -1;
    if (index != main_maze[index])
        main_maze[index] = searchSet(main_maze[index]);
    return main_maze[index];
}

bool disjointSet::sameComponent(int firstA, int secondB) {
    return searchSet(firstA) == searchSet(secondB);
}

void disjointSet::prints_the_sets() {
    for (int i = 0; i < totsize; i++)
    {
        cout << '{';
        for (int j = 0; j < totsize; j++)
        {
            if (main_maze[j] == i)
            {
                cout << j << ", ";
            }
        }
        cout << "}\n";
    }
}

void disjointSet::linker(int firstVal, int secondVal) {
    if (firstVal == secondVal) return;
    if (child_maze[firstVal] > child_maze[secondVal]) {
        main_maze[secondVal] = firstVal;
    }
    else
    {
        main_maze[firstVal] = secondVal;
        if (child_maze[firstVal] == child_maze[secondVal])
            child_maze[secondVal]++;
    }
    --setnum;
}

void disjointSet::createsSet(int firstVal) {
    if (firstVal < 0 ||firstVal >= totsize) return;
    child_maze[firstVal] = 0;
    main_maze[firstVal] = firstVal;
}