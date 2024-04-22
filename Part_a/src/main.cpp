// Project 5
#include "../include/main.h"

int main()
{
    char x;
    ifstream fin;
    // Read the maze from the file.
    string fileName = "../../maze.txt";
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
            cout << g;
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
}