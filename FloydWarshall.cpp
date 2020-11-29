//
// Created by Danish Khan on 11/28/2020.
//
#include <iostream>
#include "FloydWarshall.h"
#include <iomanip>
int inf=999999;
#define graphsize 4
void print_Warshall(int input_graph[][graphsize])
{
    for( int i =0; i<graphsize; i++) {
        for (int j = 0; j < graphsize; j++)
            if (input_graph[i][j] == inf)
                std::cout<<std::setw(5)<<std::left << "INF"<<" ";
            else std::cout<<std::setw(5)<<std::left << input_graph[i][j] << " ";
        std::cout<<"\n";
    }
}
void shortest_path(int input_graph[][4]){
    int graph[graphsize][graphsize];
    for(int i=0;i<graphsize;i++)
        for(int j=0;j<graphsize;j++)
            graph[i][j]=input_graph[i][j];

    for(int i=0;i<graphsize;i++)
        for(int j=0;j<graphsize;j++)
            for(int k=0;k<graphsize;k++)
                if(graph[i][k]+graph[j][i]<graph[j][k])
                    graph[j][k]=graph[i][k]+graph[j][i];
print_Warshall(graph);
}