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
        bool findPathRecursive(graph &g, int currentNode);
        void solveMaze(graph &g, int startingNode, int solvingMethod);
        void nodesToMoves();
        void printMoves();
        vector<int> posFromNode(int node);
        bool findPathNonRecursive(graph &g, int startNode);
        void findShortestPathWrapper(graph &g, int startNode, bool method);
        bool findShortestPath1(graph &g, int startNode);
        bool findShortestPath2(graph &g, int startNode);
        void setPath(const int startNode, const int currentNode, vector<int> prev);

    private:
        int rows; // number of rows in the maze
        int cols; // number of columns in the maze
        matrix<bool> value;
        matrix<int> map; // Mapping from maze (i,j) values to node index values
        vector<int> nodePath;
        vector<string> moveSequence;
};

#endif
