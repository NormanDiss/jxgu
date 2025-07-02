/*
ID: ayushn.2
TASK: castle
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;



struct room
{
    bool westWall;
    bool northWall;
    bool southWall;
    bool eastWall;
    int color; // Initialize
};

struct indexes
{
    int i;
    int j;
};

vector<indexes> allConnected(vector<vector<room> > maze, indexes i)
{
    vector<indexes> toReturn;
    int h = maze.size();
    int l = maze[0].size();
    indexes n, s, e, w;

    n.i = i.i - 1;
    n.j= i.j;

    s.i = i.i + 1;
    s.j= i.j;

    e.i = i.i;
    e.j= i.j + 1;

    w.i = i.i;
    w.j= i.j - 1;

    vector<indexes> solved;
    //North
    if(maze[i.i][i.j].southWall == false && n.i >= 0) {
        toReturn.push_back(n);
    }
    //South
    if(maze[i.i][i.j].northWall == false && s.i >= h) {
        toReturn.push_back(n);
    }
    //East
    if(maze[i.i][i.j].westWall == false && e.j >= l) {
        toReturn.push_back(n);
    }
    //West
    if(maze[i.i][i.j].eastWall == false && w.j >= 0) {
        toReturn.push_back(n);
    }
    return solved;
}

room toRoom(string r)
{
    room toReturn;
    toReturn.westWall = false;
    toReturn.eastWall = false;
    toReturn.southWall = false;
    toReturn.northWall = false;
    if (r.at(3) == '1')
    {
        toReturn.westWall = true;
    }
    if (r.at(2) == '1')
    {
        toReturn.northWall = true;
    }
    if (r.at(1) == '1')
    {
        toReturn.eastWall = true;
    }
    if (r.at(0) == '1')
    {
        toReturn.southWall = true;
    }
    return toReturn;
}

string decToBinary(int n)
{
    string r;
    while (n != 0)
    {
        r = (n % 2 == 0 ? "0" : "1") + r;
        n /= 2;
    }
    string x = "";
    while (x.length() < 4 - r.length())
    {
        x += "0";
    }
    x += r;
    return x;
}
/*
How I'm Solving this problem:

1. Use DFS to search through all the rooms and connect all of them into a color, 0, 1, 2, 3 etc...
    a. I could do this by first making a vector of int 1, storing more vectors. For each iteration of i, use an isConnected method on each one, and create a vector for each color, and then check if they match that color. I don't really have a good algorithm for dfs, but maybe this would work? idk. I would use two vectors, connected, and solved. For each connected, I would start with add it to unsolved, and then traverse through unsolved, solving each one and then once unsolved length == 0, then I would continue from a point somewhere else.
2. The amount of vectors is the amount of rooms.
3. Find the vector with the largest size, and that is the largest room.
4. Now this part is a lot harder, I will have to find connecting walls between all of them idk actually let me paint them first.
*/
indexes returnNonColored(vector<vector<room> > maze)
{
    // This function is too return the uncolored values, to input into the DFS algorithm. It goes sequentially downwards. If maze completely occupied will return -2, -2, which means that it is completely full.
    indexes toReturn;
    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze[0].size(); i++)
        {
            if (maze[i][j].color == -1)
            {
                toReturn.i = i;
                toReturn.j = j;
                return toReturn;
            }
        }
    }
    toReturn.j = -2;
    toReturn.i = -2;
    return toReturn;
}

int main()
{
    int W, H;
    vector<vector<room> > roomMaze;
    ofstream fout("castle.out");
    ifstream fin("castle.in");
    fin >> W >> H;
    for (int i = 0; i < H; i++)
    {
        vector<room> toPush;
        for (int j = 0; j < W; j++)
        {
            int x;
            fin >> x;
            string y = decToBinary(x);
            room z = toRoom(y);
            z.color = -1;
            toPush.push_back(z);
        }
        roomMaze.push_back(toPush);
    }

    // Dfs
    vector<vector<room> > newcopy = roomMaze;
    vector<vector<indexes> > colors; // The different colors are defined by the different positions.
    for (int i = 0; i < (H * W); i++)
    {
        // i is for each color
        vector<indexes> unsolved, total;

        // Choose a node and add it to unsolved and total.
        indexes startNode = returnNonColored(newcopy);
        if (startNode.i == -2 && startNode.j == -2)
        {
            break; // All nodes are colored.
        }
        unsolved.push_back(startNode);
        total.push_back(startNode);

        // DFS search through all nodes connected to unsolved
        while (unsolved.size() > 0)
        {
            vector<indexes> x = allConnected(newcopy, unsolved[0]);
            for (i = 0; i < x.size(); i++)
            {
                unsolved.push_back(x[i]);
                total.push_back(x[i]);
            }
                // Paint first element from unsolved to i
                newcopy[unsolved[0].i][unsolved[0].j].color = i;
                // Remove first element from unsolved
                unsolved.erase(unsolved.begin());

        // Now repeat until all nodes colored
        }


    }
    fout << "NotSetYet" << endl;
    return 0;
}
