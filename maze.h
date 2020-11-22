//
// Created by Danish Khan on 11/22/2020.
//

#ifndef CMPE130_MAZE_H
#define CMPE130_MAZE_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <utility>
#include "disjoint.h"

using namespace std;

class Maze {
public :
    Maze();

    Maze(int = 10);

    ~Maze();

    void printMaze();

private :
    void render();

    void clearWall(int index);

    int make_Wall(int index);

    int adjacent(int num, int wall_side);

    bool check_adjacent(int i, int wall_side);

    int check_opposite_wall(int wall_side);

    void randomizeIndices();

    int *maze_wall_status;
    disjointSet *disjoint_set;
    int *indexArray;
    int mazeSizeN;
    int mazeSize;
    static const int right = 1;
    static const int left = 4;
    static const int top = 8;
    static const int bottom = 2;
    static const int wallValues[];
};

#endif //CMPE130_MAZE_H
