#ifndef MAZE_H
#define MAZE_H

#include "graph.h"

class maze
{
    public:
        maze(ifstream &fin);
        void print(int,int,int,int);
        bool isLegal(int i, int j);
        void setMap(int i, int j, int n);
        int getMap(int i, int j) const;
        void mapMazeToGraph(maze &m, graph &g);
    private:
        int rows; // number of rows in the maze
        int cols; // number of columns in the maze
        matrix<bool> value;
        matrix<int> map; // Mapping from maze (i,j) values to node index values
};

#endif