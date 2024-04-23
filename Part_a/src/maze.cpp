#include "../include/maze.h"

void maze::setMap(int i, int j, int n)
// Set mapping from maze cell (i,j) to graph node n.
{
    map[i][j] = n;
}

int maze::getMap(int i, int j) const
// Return mapping of maze cell (i,j) in the graph.
{
    return map[i][j];
}

maze::maze(ifstream &fin)
// Initializes a maze by reading values from fin. Assumes that the
// number of rows and columns indicated in the file are correct.
{
    fin >> rows;
    fin >> cols;
    char x;
    value.resize(rows,cols);
    for (int i = 0; i <= rows-1; i++)
        for (int j = 0; j <= cols-1; j++)
        {
            fin >> x;
            if (x == 'O')
                value[i][j] = true;
            else
                value[i][j] = false;
        }
    map.resize(rows,cols);
}

void maze::print(int goalI, int goalJ, int currI, int currJ)
// Print out a maze, with the goal and current cells marked on the
// board.
{
    cout << endl;
    if (goalI < 0 || goalI > rows || goalJ < 0 || goalJ > cols)
        throw rangeError("Bad value in maze::print");
    if (currI < 0 || currI > rows || currJ < 0 || currJ > cols)
        throw rangeError("Bad value in maze::print");
    for (int i = 0; i <= rows-1; i++)
    {
        for (int j = 0; j <= cols-1; j++)
        {
            if (i == goalI && j == goalJ)
                cout << "*";
            else
                if (i == currI && j == currJ)
                    cout << "+";
                else
                    if (value[i][j])
                        cout << " ";
                    else
                        cout << "X";
        }
        cout << endl;
    }
    cout << endl;
}

bool maze::isLegal(int i, int j)
// Return the value stored at the (i,j) entry in the maze.
{
    if (i < 0 || i > rows || j < 0 || j > cols)
        throw rangeError("Bad value in maze::isLegal");
    return value[i][j];
}
void maze::mapMazeToGraph(maze &m, graph &g)
// Create a graph g that represents the legal moves in the maze m.
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            NodeWeight weight;
            setMap(i, j, g.numNodes());
            if (m.isLegal(i,j))
                weight = 1;
            else
                weight = 0;
            g.addNode(weight);
        }
    }
    for (int i = 0; i < g.numNodes(); i++)
    {
        if (g.getNodeWeight(i))
        {
            for (int j = 0; j < g.numNodes(); j++)
            {
                if (g.getNodeWeight(j))
                {
                    if (abs(i-j) == 1 || abs(i-j) == cols)
                    {
                        g.addEdge(i, j, 1);
                    }
                }
            }
        }
    }
}

void maze::nodesToMoves()
{
    int currentNode;
    int nextNode;
    moveSequence.clear();
    for (int i = 0; i < nodePath.size()-1; i++)
    {
        currentNode = nodePath[i];
        nextNode = nodePath[i+1];
        if (nextNode-currentNode == 1)
            moveSequence.push_back("Go right");
        else if (nextNode-currentNode == -1)
            moveSequence.push_back("Go left");
        else if (nextNode-currentNode == 10)
            moveSequence.push_back("Go down");
        else
            moveSequence.push_back("Go up");
    }
}

vector<int> maze::posFromNode(int node)
{
    int i = node/cols;
    int j = node%cols;
    vector<int> coordinates;
    coordinates.push_back(i);
    coordinates.push_back(j);
    return coordinates;
}

void maze::printMoves()
{
    print(rows-1, cols-1, posFromNode(nodePath[0])[0], posFromNode(nodePath[0])[1]);
    for (int i = 1; i < nodePath.size(); i++)
    {
        cout << "###################\n" << endl;
        cout << moveSequence[i-1] << ":" << endl;
        print(rows-1, cols-1, posFromNode(nodePath[i])[0], posFromNode(nodePath[i])[1]);
        cout << "###################" << endl;
    }
}

void maze::solveMaze(graph &g, int startingNode, int solvingMethod)
{
    nodePath.clear();
    bool pathFound = 0;
    if (solvingMethod == 0)
        pathFound = findPathRecursive(g, startingNode);

    if (!pathFound)
    {
        cout << "No path exists" << endl;
    }
    else 
    {
        nodesToMoves();
        cout << "\n###\nSequence of Correct Moves:" << endl;
        cout << moveSequence[0];
        for (int i = 1; i < moveSequence.size(); i++)
        {
            cout << ", " << moveSequence[i];
        }
        cout << endl;
    }
    printMoves();
}

bool maze::findPathRecursive(graph &g, int currentNode)
{
    g.visit(currentNode);

    if (getMap(rows-1, cols-1) == currentNode)
    {
        nodePath.insert(nodePath.begin(), currentNode);
        return true;
    }
    for (int i = 0; i < g.numNodes(); i++)
    {
        if (g.isEdge(currentNode, i) && !g.isVisited(i))
        {
            if (findPathRecursive(g, i))
            {
                nodePath.insert(nodePath.begin(), currentNode);
                return true;
            }
        }
    }
    return false;
}