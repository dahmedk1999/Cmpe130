//
// Created by Danish Khan on 11/22/2020.
//
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Maze.h"

using std::cout;

using std::hex;
using std::swap;

Maze::Maze() {}

Maze::Maze(int size) {
    if (size < 3) {
        cout << "Choose a bigger size" << endl;
        exit(1);
    }
    mazeSizeN = size;
    mazeSize = int(pow(mazeSizeN, 2));
    disjoint_set = new disjointSet(mazeSize);
    maze_wall_status = new int[mazeSize];
    maze_wall_status[0] = 11;//B
    maze_wall_status[mazeSize - 1] = 14;//E
    for (int i = 1; i < mazeSize - 1; i++)
        maze_wall_status[i] = 15;//F
    indexArray = new int[mazeSize];
    for (int i = 0; i < mazeSize; i++)
        indexArray[i] = i;
    //printMaze();
    render();
}

Maze::~Maze() {
    delete[]maze_wall_status;
    delete[]indexArray;
    delete disjoint_set;
}

void Maze::printMaze() {
    for (int i = 0; i < mazeSize; i++) {
        cout << hex << maze_wall_status[i];
        if ((i + 1) % mazeSizeN == 0) {
            cout << "\n";
        }
    }
}

void Maze::render() {
    randomizeIndices();
    int i = 0;
    while (disjoint_set->getNumSets() > 1 && i <mazeSize) {
        clearWall(indexArray[i]);
        ++i;
    }
    //never reaches here!
}

void Maze::clearWall(int index) {
    int wall;
    int adj;
    for (int j = 0; j < 2; j++) {
        wall = make_Wall(index);
        adj = adjacent(index, wall);
        if (!disjoint_set->sameComponent(index, adj)) {
            maze_wall_status[index] = maze_wall_status[index] - wall;
            maze_wall_status[adj] = maze_wall_status[adj] - check_opposite_wall(wall);
            disjoint_set->union_function(index, adj);
            return;
        }
    }
}

int Maze::make_Wall(int index) {
    int maze_Wall;
    do {
        maze_Wall = wallValues[rand() % 4];
    } while (!check_adjacent(index, maze_Wall));
    return maze_Wall;
}

int Maze::adjacent(int num, int wall_side) {
    if (wall_side == right)
        return (num+1);
    if (wall_side == left)
        return (num-1);
    if (wall_side == top)
        return (num - mazeSizeN);
    if (wall_side == bottom)
        return (num + mazeSizeN);
}

bool Maze::check_adjacent(int i, int wall_side) {
    return (wall_side == bottom && i + mazeSizeN < mazeSize) || (wall_side == top && i - mazeSizeN >= 0) ||
           (wall_side == left && i - 1 >= 0 && i % mazeSizeN != 0) ||
           (wall_side == right && i + 1 < mazeSize && (i + 1) % mazeSizeN != 0);
}

int Maze::check_opposite_wall(int wall_side) {
    if (wall_side == right)
        return left;
    if (wall_side == left)
        return right;
    if (wall_side == top)
        return bottom;
    if (wall_side == bottom)
        return top;
}

void Maze::randomizeIndices() {
    srand(time(0));
    int random_index_num;
    for (int i = 0; i < mazeSize; i++) {
        random_index_num = rand() % mazeSize;
        swap(indexArray[i], indexArray[random_index_num]);
    }
}

const int Maze::wallValues[] = {right, left, top, bottom};