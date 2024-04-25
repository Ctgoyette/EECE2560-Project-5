// Project 5
#include "../include/maze.h"

int main()
{
    char x;
    ifstream fin;

    vector<string> mazeFiles = {"../../maze1.txt", "../../maze2.txt", "../../maze3.txt"};
    // Read the maze from the file.
    string fileName;
    for (int i = 0; i < mazeFiles.size(); i++)
    {
        fileName = mazeFiles[i];
        fin.open(fileName.c_str());
        if (!fin)
        {
            cerr << "Cannot open " << fileName << endl;
            exit(1);
        }
        try
        {
            graph g;
            while (fin && fin.peek() != 'Z')
            {
                maze m(fin);
                m.mapMazeToGraph(m, g);
                //m.solveMaze(g, 0, 0);
                //m.solveMaze(g, 0, 1);
                //m.findShortestPathWrapper(g, 0, 0);
                m.findShortestPathWrapper(g, 0, 0);
            }
        }
        catch (indexRangeError &ex)
        {
            cout << ex.what() << endl; exit(1);
        }
        catch (rangeError &ex)
        {
            cout << ex.what() << endl; exit(1);
        }
        cout << endl;

        fin.close();
        cout << "View output from last maze solution, then type anything and press enter to solve the next maze" << endl;
        string notUsed;
        cin >> notUsed;
    }
}
